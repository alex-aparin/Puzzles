#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

typedef vector<vector<int>> map_type;
typedef vector<vector<bool>> bool_map_type;

bool is_watershed(const map_type& land, bool_map_type& used_land, const int i, const int j)
{
    bool res = true;
    list<int> steps;
    steps.push_back(i);
    steps.push_back(j);
    while (!steps.empty())
    {
        const int j = steps.back();
        steps.pop_back();
        const int i = steps.back();
        steps.pop_back();
        used_land[i][j] = true;
        const int i_steps[4] = {   i,     i, i - 1, i + 1};
        const int j_steps[4] = { j-1, j + 1,     j,     j};
        for (int k = 0; k < 4; ++k)
        {
            const int new_i = i_steps[k];
            const int new_j = j_steps[k];
            res = res && land[i][j] <= land[new_i][new_j];
            if (!used_land[new_i][new_j] && land[new_i][new_j] == land[i][j])
            {
                steps.push_front(new_j);
                steps.push_front(new_i);
            }
        }
    }
    return res;
}

int main()
{
    const int infty_height = 10000 + 1;
    int W;
    int H;
    cin >> W >> H; cin.ignore();
    map_type land(H + 2, vector<int>(W + 2, infty_height));
    bool_map_type used_land(H + 2, vector<bool>(W + 2, false));
    for (int i = 1; i <= H; ++i) 
        for (int j = 1; j <= W; ++j) 
        {
            if (i == 0 || j == 0 || i == H + 1 || j == W + 1)
                used_land[i][j] = true;
            else
            {
                cin >> land[i][j]; cin.ignore();
            }
        }
    int min_watersheds = 0;
    for (int i = 1; i <= H; ++i)
        for (int j = 1; j <= W; ++j)
        {
            if (used_land[i][j])
                continue;
            min_watersheds += is_watershed(land, used_land, i, j) ? 1 : 0;
        }
    cout << min_watersheds << endl;
}
