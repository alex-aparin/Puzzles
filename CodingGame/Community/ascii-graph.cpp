#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N; cin.ignore();
    int left_x = -1;
    int right_x = 1;
    int top_y = 1;
    int bottom_y = -1;
    vector<pair<int, int>> points(N, make_pair(0, 0));
    for (int i = 0; i < N; i++)
    {
        cin >> points[i].first >> points[i].second; cin.ignore();
        left_x = min(left_x, points[i].first - 1);
        right_x = max(right_x, points[i].first + 1);
        bottom_y = min(bottom_y, points[i].second - 1);
        top_y = max(top_y, points[i].second + 1);
    }
    sort(points.begin(), points.end(), 
        [](const pair<int, int> lhs, const pair<int, int> rhs)
        {
            if (lhs.second == rhs.second)
                return lhs.first < rhs.first;
            return lhs.second > rhs.second;
        });
    size_t curr_point = 0;
    for (int i = top_y; bottom_y <= i; --i)
    {
        for (int j = left_x; j <= right_x; ++j)    
        {
            if (curr_point < points.size() && points[curr_point].first == j && points[curr_point].second == i)
            {
                ++curr_point;
                cout << '*';
                continue;
            }
            if (j == 0 && i == 0)
            {
                cout << '+';
                continue;
            }
            if (j == 0)
            {
                cout << '|';
                continue;
            }
            if (i == 0)
            {
                cout << '-';
                continue;
            }
            cout << '.';
        }
        cout << endl;
    }
}
