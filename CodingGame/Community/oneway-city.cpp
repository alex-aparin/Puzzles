#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef size_t num_type;

num_type compute_binom(const int n, const int k)
{
    num_type res = 1;
    for (int i = 0; i < k; ++i)
        res = res * (n - i) / (i + 1);
    return res;
}
int main()
{
    int M;
    cin >> M; cin.ignore();
    int N;
    cin >> N; cin.ignore();
    cout << compute_binom(M + N - 2, max(N, M) - 1) << endl;
}
