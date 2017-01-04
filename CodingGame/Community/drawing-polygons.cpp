#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cross_product(const pair<int, int>& lhs, const pair<int, int>& mid, const pair<int, int> rhs)
{
    return (rhs.first - mid.first) * (mid.second - lhs.second) - (rhs.second - mid.second) * (mid.first - lhs.first);
}

int main()
{
    int N;
    cin >> N; cin.ignore();
    vector<pair<int, int>> polygon(N, make_pair(0, 0));
    int min_x_id = 0;
    for (int i = 0; i < N; i++) 
    {
        cin >> polygon[i].first >> polygon[i].second; cin.ignore();
        if (polygon[i].first < polygon[min_x_id].first)
            min_x_id = i;
    }
    const bool clockwise = 0 < cross_product(polygon[(min_x_id + polygon.size() - 1) % polygon.size()], polygon[min_x_id], polygon[(min_x_id + 1) % polygon.size()]);
    const char* const answer = clockwise ? "CLOCKWISE" : "COUNTERCLOCKWISE";
    cout << answer << endl;
}
