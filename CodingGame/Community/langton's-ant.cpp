#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<string> land_type;

class LangtonAnt
{
public:
    LangtonAnt(land_type& land, const char dir, const int x, const int y, const int steps) : 
        m_land(land), m_dir(dir), m_x(x), m_y(y), m_steps(steps)
    {
    }
    
    bool move_next()
    {
        if (m_steps == 0)
            return false;
        --m_steps;
        const char cur_c = m_land[m_y][m_x];   
        const bool left = cur_c == '.';
        m_land[m_y][m_x] = cur_c == '.' ? '#' : '.';
        switch  (m_dir)
        {
            case 'W':
                m_dir = left ? 'S' : 'N';
            break;
            case 'S':
                m_dir = left ? 'E' : 'W';
            break;
            case 'E':
                m_dir = left ? 'N' : 'S';
            break;
            case 'N':
                m_dir = left ? 'W' : 'E';
            break;
        }
        switch  (m_dir)
        {
            case 'E':
                ++m_x;
            break;
            case 'S':
                ++m_y;
            break;
            case 'W':
                --m_x;
            break;
            case 'N':
                --m_y;
            break;
        }
        return true;
    }
private:
    land_type& m_land;
    char m_dir;
    int m_x;
    int m_y;
    int m_steps;
};

int main()
{
    int W;
    int H;
    cin >> W >> H; cin.ignore();
    int x;
    int y;
    cin >> x >> y; cin.ignore();
    char direction;
    cin >> direction; cin.ignore();
    int T;
    cin >> T; cin.ignore();
    
    land_type land;
    land.reserve(H);
    for (int i = 0; i < H; i++) 
    {
        string C;
        getline(cin, C);
        land.push_back(C);
    }
    LangtonAnt ant(land, direction, x, y, T);
    cerr << W << H << endl;
    cerr << x << y << endl;
    cerr << direction << endl;
    cerr << T << endl;
    for (; ant.move_next(); ) ;
    for (int i = 0; i < H; i++) 
        cout << land[i] << endl;
}
