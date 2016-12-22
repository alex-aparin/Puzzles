#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Cell
{
public:
	explicit Cell(const char c) : 
		m_val(c), m_visited(false)
	{
	}
	char get_val(void) const
	{
		return m_val;
	}
	void set_val(const char c)
	{
		m_val = c;
	}
	bool is_zerg(void) const
	{
		return m_val == 'z';
	}
	bool is_empty(void) const
	{
		return m_val == '.';
	}
	bool is_obstacle(void) const
	{
		return m_val == '#';
	}
	bool is_building(void) const
	{
		return m_val == 'B';
	}
	bool is_visited(void) const
	{
		return m_visited;
	}
	void visit(void)
	{
		m_visited = true;
	}
private:
	char m_val;
	bool m_visited;
};

class Land
{
public:
	Land(const size_t W, const size_t H) : 
		m_cells(H, vector<Cell>(W, Cell('_')))
	{
	}
	void set_val(const size_t i, const size_t j, const char c)
	{
		m_cells[i][j].set_val(c);
	}
	char get_val(const size_t i, const size_t j) const
	{
		return m_cells[i][j].get_val();
	}
	void settle_by_zergs(void)
	{
		const size_t H = m_cells.size();
		const size_t W = m_cells[0].size();
		for (size_t i = 0; i < H; ++i)
		{
			move_zerg(0, i, 0);
			move_zerg(0, i, W - 1);
		}
		for (size_t j = 0; j < W; ++j)
		{
			move_zerg(0, 0, j);
			move_zerg(0, H - 1, j);
		}
	}
private:
	void move_zerg(Cell* prev_cell, const size_t i, const size_t j)
	{
		Cell& cell = m_cells[i][j];
		if (cell.is_visited() || cell.is_building() || cell.is_obstacle())
			return;
		for (int v = -1; v < 2; ++v)
			for (int h = -1; h < 2; ++h)
			{
				if (cell.is_empty() && 0 <= v + i && v + i < m_cells.size() && 0 <= h + j && h + j < m_cells[i].size() && m_cells[v+i][h+j].is_building())
					cell.set_val('z');
			}
		cell.visit();	
		const vector<int> xs = {-1, 0, 1, 0};
		const vector<int> ys = { 0, 1, 0, -1};
		for (int step_index = 0; step_index < 4; ++step_index)
		{
			if (0 <= ys[step_index] + i && ys[step_index] + i < m_cells.size() && 0 <= xs[step_index] + j && xs[step_index] + j < m_cells[i].size())
				move_zerg(&cell, ys[step_index] + i , xs[step_index] + j);
		}
	}
	vector<vector<Cell>> m_cells;
};
int main()
{
	size_t W;
	size_t H;
	cin >> W >> H; cin.ignore();
	Land land(W, H);
	for (size_t i = 0; i < H; ++i) {
		string ROW;
		getline(cin, ROW);
		for (size_t j = 0; j < W; ++j)
			land.set_val(i, j, ROW[j]);
	}
	land.settle_by_zergs();
	for (size_t i = 0; i < H; ++i)
	{
		for (size_t j = 0; j < W; ++j)
			cout << land.get_val(i, j);
		cout << endl;
	}
}
