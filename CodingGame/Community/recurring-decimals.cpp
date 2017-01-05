#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void fill(const int D, vector<int>& numbers, int& preted_id)
{
    int N = 1;
    map<int, int> rep_nums;
    for (int pos = 0; N != 0 && rep_nums.find(N) == rep_nums.end(); ++pos)
    {
        rep_nums.insert(make_pair(N, pos));
        numbers.push_back(N / D);
        N = (N % D) * 10;
    }
    if (N != 0)
        preted_id = rep_nums[N];
}
int main()
{
    int n;
    cin >> n; cin.ignore();
    vector<int> nums;
    int retend = -1;
    fill(n, nums, retend);
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i == retend)
            cout << "(";
        cout << nums[i];
        if (i == 0)
            cout << ".";
    }
    if (retend != -1)
        cout << ")";
    cout << endl;
}
