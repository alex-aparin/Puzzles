#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct SandPile
{
public:
	SandPile(const int size) :
		m_size(size), m_field(size, vector<int>(size, 0))
	{
	}
	SandPile operator+(const SandPile& rhs) const
	{
		SandPile res = SandPile(m_size);
		for (int i = 0; i < m_size; ++i)
			for (int j = 0; j < m_size; ++j)
				res.m_field[i][j] = m_field[i][j] + rhs.m_field[i][j];
		return res;
	}
	void to_sandpile(void)
	{
		bool should_modify = true;
		while (should_modify)
		{
			should_modify = false;
			for (int i = 0; i < m_size; ++i)
				for (int j = 0; j < m_size; ++j)
				{
					if (m_field[i][j] < 4)
						continue;
					should_modify = true;
					m_field[i][j] -= 4;
					if (0 < i)
						++m_field[i - 1][j];
					if (i + 1 < m_size)
						++m_field[i + 1][j];
					if (0 < j)
						++m_field[i][j - 1];
					if (j + 1 < m_size)
						++m_field[i][j + 1];
				}
		}
	}
private:
	int exceed_grain_pos(void) const
	{
		for (int i = 0; i < m_size; ++i)
			for (int j = 0; j < m_size; ++j)
			{
				if (m_field[i][j] > 3)
					return i * m_size + j;
			}
		return -1;
	}
	friend istream& operator>> (istream& is, SandPile& dt);
	friend ostream& operator<< (ostream& os, const SandPile& dt);
	const int m_size;
	vector<vector<int>> m_field;
};

istream& operator>> (istream& is, SandPile& dt)
{
	for (int i = 0; i < dt.m_size; ++i)
	{
		string row;
		is >> row;
		for (int j = 0; j < dt.m_size; ++j)
			dt.m_field[i][j] = row[j] - '0';
	}
	return is;
}

ostream& operator<< (ostream& os, const SandPile& dt)
{
	for (int i = 0; i < dt.m_size; ++i)
	{
		for (int j = 0; j < dt.m_size; ++j)
			os << (char)(dt.m_field[i][j] + (int)'0');
		os << endl;
	}
	return os;
}

int main()
{
	int n;
	cin >> n; cin.ignore();
	SandPile lhs = SandPile(n);
	SandPile rhs = SandPile(n);
	cin >> lhs;
	cin >> rhs;
	SandPile res = lhs + rhs;
	res.to_sandpile();
	cout << res;
}
