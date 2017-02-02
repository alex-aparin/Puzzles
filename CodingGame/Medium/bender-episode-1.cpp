#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct CellProperty
{
    CellProperty(const char dir, const bool is_breaker, const bool is_inversed, const string& map_state):
        m_dir(dir), m_is_breaker(is_breaker), m_is_inversed(is_inversed), m_map_state(map_state)
    {}
    bool operator ==(const CellProperty& other)
    {
        return m_dir = other.m_dir && 
        m_is_breaker == other.m_is_breaker && 
        m_is_inversed == other.m_is_inversed &&
        m_map_state == other.m_map_state;
    }
    char m_dir;
    bool m_is_breaker;
    bool m_is_inversed;
    string m_map_state;
};

typedef pair<char, CellProperty*> cell_type;
typedef vector<cell_type> map_line_type;
typedef vector<map_line_type> map_type;

bool cell_can_have_property(const char c)
{
    return c == 'S' || c == 'E' || c == 'N' || c == 'W' || c == '#' || c == 'X' || c == 'I';
}

bool use_cerr = true;

struct Bender
{
    Bender(const map_type& _map) : m_x(0), m_y(0), m_dir('S'), m_map(_map)
    {
        m_is_turning = false;
        m_is_breaker = false;
        m_is_inversed = false;
        bool start_pos_is_exist = false;
        bool end_pos_is_exist = false;
        for (int i = 0; i < m_map.size(); ++i)
            for (int j = 0; j < m_map[i].size(); ++j)
            {
                if (m_map[i][j].first == '@')
                {
                    m_x = j;
                    m_y = i;
                    start_pos_is_exist = true;
                }
                if (m_map[i][j].first == '$')
                    end_pos_is_exist = true;
                if (m_map[i][j].first == 'X')
                    m_map_state.push_back(m_map[i][j].first);
            }
        sort(m_map_state.begin(), m_map_state.end());
        m_map_is_corrected = start_pos_is_exist && end_pos_is_exist;
    }
    ~Bender()
    {
        // for (int i = 0; i < m_map.size(); ++i)
        //     for (int j = 0; j < m_map[i].size(); ++j)
        //     {
        //         if (m_map[i][i].second != 0)
        //         {
        //             delete m_map[i][i].second;
        //             m_map[i][i].second = 0;
        //         }
        //     }
    }
    void turn_direction(void)
    {
        switch (m_dir)
    	{
    		case 'S':
    			m_dir = m_is_inversed == false ? 'E' : 'W';
    		break; 
    		case 'E':
    			m_dir = m_is_inversed == false ? 'N' : 'S';
    		break;
    		case 'N':
    			m_dir = m_is_inversed == false ? 'W' : 'E';
    		break;
    		case 'W':
    			m_dir = m_is_inversed == false ? 'S' : 'N';
    		break;
    		default:
    			throw "Unexpected case branch";
    	}
    }
    void compute_next_step(int&x, int&y)
    {
        x = m_x;
        y = m_y;
        switch (m_dir)
    	{
    		case 'S':
    			y += 1;
    		break; 
    		case 'E':
    			x += 1;
    		break;
    		case 'N':
    			y -= 1;
    		break;
    		case 'W':
    			x -= 1;
    		break;
    		default:
    			throw "Unexpected case branch";
    	}
    }
    CellProperty get_cell_property(void) const
    {
       return CellProperty(m_dir, m_is_breaker, m_is_inversed, m_map_state);
    }
    bool can_reach_death_booth(void) 
    {
        if (use_cerr)
        {
            cerr << " Can reach death booth method :" << endl;
            cerr << "Map is corrected : " << m_map_is_corrected << endl;
        }
        if (m_map_is_corrected == false)
            return false;
        while (perform_step())
            ;
        return m_map[m_y][m_x].first == '$';
        
    }
    bool perform_step(void)
    {
        if (use_cerr)
        {
            cerr << "[" << m_y << "][" << m_x << "]" << endl;
            cerr << "Current symbol : " << m_map[m_y][m_x].first << endl;
            cerr << "Current direction : " << m_dir << endl;
        }
        if (m_map[m_y][m_x].first == '$')
            return false;
        int x;
        int y;
        compute_next_step(x, y);
        if (cell_can_have_property(m_map[y][x].first))
        {
            if (m_map[y][x].second == 0)
                m_map[y][x].second = new CellProperty(get_cell_property());
            else if (*m_map[y][x].second == get_cell_property())
            {
                if (m_is_turning == false)
                    return false;
            }
            else
                *m_map[y][x].second = get_cell_property();
        }
        if (m_map[y][x].first == ' ' || m_map[y][x].first == '@')
        {
            if (use_cerr == false)
                print_current_direction();
            m_is_turning = false;
            m_x = x;
            m_y = y;
            return true;
        }
        if (m_map[y][x].first == 'I')
        {
            if (use_cerr == false)
                print_current_direction();
            m_is_turning = false;
            m_is_inversed = !m_is_inversed;
            m_x = x;
            m_y = y;
            return true;
        }
        if (m_map[y][x].first == 'T')
        {
            if (use_cerr == false)
                print_current_direction();
            m_is_turning = false;
            m_x = x;
            m_y = y;
            for (int i = 0; i < m_map.size(); ++i)
            for (int j = 0; j < m_map[i].size(); ++j)
                if (m_map[i][j].first == 'T')
                {
                    if (i != y || j != x)
                    {
                        m_x = j;
                        m_y = i;
                        break;
                    }
                }
            return true;
        }
        if (m_map[y][x].first == '#')
        {
            if (m_is_turning || m_dir == get_pior_dir())
                turn_direction();
            else
                m_dir = get_pior_dir();
            m_is_turning = true;
            return true;
        }
        if (m_map[y][x].first == 'X')
        {
            if (!m_is_breaker)
            {
                if (m_is_turning || m_dir == get_pior_dir())
                    turn_direction();
                else
                    m_dir = get_pior_dir();
                m_is_turning = true;
                return true;
            }
            if (use_cerr == false)
                print_current_direction();
            m_is_turning = false;
            m_map[y][x].first = ' ';
            delete m_map[y][x].second;
            m_map[y][x].second = 0;
            m_map_state.pop_back();
            m_x = x;
            m_y = y;
            return true;
        }
        if (m_map[y][x].first == 'S' || m_map[y][x].first == 'E' || 
            m_map[y][x].first == 'N' || m_map[y][x].first == 'W')
        {
            if (use_cerr == false)
                print_current_direction();
            m_is_turning = false;
            m_x = x;
            m_y = y;
            m_dir = m_map[y][x].first;
            return true;
        }
        if (m_map[y][x].first == '$')
        {
            if (use_cerr == false)
                print_current_direction();
            m_is_turning = false;
            m_x = x;
            m_y = y;
            return false;
        }
        if (m_map[y][x].first == 'B')
        {
            if (use_cerr == false)
                print_current_direction();
            m_is_breaker = !m_is_breaker;
            m_is_turning = false;
            m_x = x;
            m_y = y;
            return true;
        }
        if (use_cerr)
        cerr << "Unexpected: " << m_map[y][x].first << endl;
        m_is_turning = false;
        throw "Unexpected condition";
        return true;
    }
    void print_current_direction(void)
    {
        switch (m_dir)
    	{
    		case 'S':
    			cout << "SOUTH" << endl;
    		break; 
    		case 'E':
    			cout << "EAST" << endl;
    		break;
    		case 'N':
    			cout << "NORTH" << endl;
    		break;
    		case 'W':
    			cout << "WEST" << endl;
    		break;
    		default:
    			throw "Unexpected case branch";
    	}
    }
    char get_pior_dir(void) const
    {
        return m_is_inversed == false ? 'S' : 'W';
    }
    int m_x;
    int m_y;
    char m_dir;
    bool m_is_breaker;
    bool m_is_inversed;
    string m_map_state;
    bool m_map_is_corrected;
    map_type m_map;
    bool m_is_turning;
};

int main()
{
    int L;
    int C;
    cin >> L >> C; cin.ignore();
    map_type _map(L);
    for (int i = 0; i < L; i++) {
        map_line_type map_line(C);
        string row;
        getline(cin, row);
        for (int k = 0; k < row.size(); ++k)
            map_line[k] = cell_type(row[k], 0);
        _map[i] = map_line;
    }
    bool can_reach_death_booth = false;
    {
        Bender bender(_map);
        can_reach_death_booth = bender.can_reach_death_booth();
        use_cerr = false;
    }
    if (can_reach_death_booth)
    {
        cerr << " SOLUTION steps :" << endl;
        Bender bender(_map);    
        while (bender.perform_step() == true)
        ;
    }
    else
        cout << "LOOP" << endl;
}
