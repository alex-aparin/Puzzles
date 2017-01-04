#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class VortexIterator
{
public:
    VortexIterator(vector<vector<int>>& matrix, const int corner) : 
        m_matrix(matrix), m_x(corner), m_y(corner), m_off_x(0), m_off_y(1), 
        m_poss_h(matrix.size() - 2 * corner), m_poss_w(matrix[0].size() - 2 * corner), 
        m_rest_step(m_poss_h - 1)
    {
    }
    int& operator*(void)
    {
        return m_matrix[m_y][m_x];
    }
    void operator++(void)
    {
        if (m_rest_step == 0)
        {
            if (m_off_x == 1 || m_off_x == -1)
            {
                m_off_x *= -1;
                m_off_y *= -1;
            }
            swap(m_off_x, m_off_y);
            m_rest_step = m_off_x * m_off_x * m_poss_w + 
                          m_off_y * m_off_y * m_poss_h - 1;
        }
        --m_rest_step;
        m_x += m_off_x;
        m_y += m_off_y;
    }
    int path_length(void) const
    {
        return 2 * (m_poss_h + m_poss_w) - 4;
    }
private:
    vector<vector<int>>& m_matrix;
    int m_x;
    int m_y;
    int m_off_x;
    int m_off_y;
    const int m_poss_h;
    const int m_poss_w;
    int m_rest_step;
};

int main()
{
    int W;
    int H;
    cin >> W >> H; cin.ignore();
    int X;
    cin >> X; cin.ignore();
    vector<vector<int>> matr(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) 
        for (int j = 0; j < W; j++) 
        {
            cin >> matr[i][j]; cin.ignore();
        }
    const int steps = min(H, W) / 2;
    for (int i = 0; i < steps; ++i)
    {
        VortexIterator iterator(matr, i);
        list<int> swap_vals;
        const int path_length = iterator.path_length();
        for (int step = path_length - X % path_length; 0 <= step; --step, ++iterator)
            ;
        for (int step = 0; step < X; ++step, ++iterator)
            swap_vals.push_back(*iterator);
        for (int step = 0; step < path_length; ++step, ++iterator)
        {
            swap_vals.push_back(*iterator);
            int val = swap_vals.front();
            swap(*iterator, val);
            swap_vals.pop_front();
        }
    }
    for (int i = 0; i < matr.size(); ++i)
    {
        for (int j = 0; j < matr[i].size(); ++j)
        {   
            if (j != 0)
                cout << " ";
            cout << matr[i][j];
        }
        cout << endl;
    }
}
