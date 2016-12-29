#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    list<pair<int, int>> min_positions;
    int max_beaut_number = 0;
    int n;
    cin >> n; cin.ignore();
    vector<int> values;
    values.reserve(n);
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai; cin.ignore();
        values.push_back(ai);
        if (min_positions.empty())
            min_positions.push_back(make_pair(ai, 0));
        if (ai < min_positions.back().first)
            min_positions.back().first = ai;
    }
    size_t i = 0;
    for (; i < values.size(); ++i)
    {
        int min_left = i;
        while (min_positions.back().first > values[i])
        {
            min_left = min_positions.back().second;
            const int beaut_num = (i - min_positions.back().second) * min_positions.back().first;
            max_beaut_number = max_beaut_number < beaut_num ? beaut_num : max_beaut_number;
            min_positions.pop_back();
        }
        if (min_positions.back().first < values[i])
            min_positions.push_back(make_pair(values[i], min_left));
    }
    while (!min_positions.empty())
    {
        const int beaut_num = (i - min_positions.back().second) * min_positions.back().first;
        max_beaut_number = max_beaut_number < beaut_num ? beaut_num : max_beaut_number;
        min_positions.pop_back();
    }
    cout << max_beaut_number << endl;
}
