#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long num_type;

num_type decompose(const num_type N)
{
    cerr << "N: " << N << endl;
    //  TODO: (alex) optimize algorithm
    num_type min_surf = N * 6;
    for (num_type i = N; 1 <= i; --i)
    {
        if (N % i != 0)
            continue;
        for (num_type j = i; 1 <= j; --j)
        {
            if (N % j != 0 || N % (i * j) != 0)
                continue;
            const num_type temp = 2 * (i * j + N / i + N / j);
            if (temp < min_surf)
                min_surf = temp;
        }
    }
    return min_surf;
}

int main()
{
    num_type N;
    cin >> N; cin.ignore();
    const num_type max_surf = 4 * N + 2;
    const num_type min_surf = decompose(N);
    cout << min_surf << " " << max_surf << endl;
}
