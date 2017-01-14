#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int n;
    int k;
    {
        ifstream myfile("./rosalind_fib.txt");
        if (!myfile.is_open())
            return 1;
        myfile >> n;
        myfile >> k;
        myfile.close();
    }
    long long prev_overall_count = 1;
    long long overall_count = 1;
    for (int i = 3; i <= n; ++i)
    {
        prev_overall_count = k * prev_overall_count + overall_count;
        swap(prev_overall_count, overall_count);
    }
    cout << overall_count;
    return 0;
}
