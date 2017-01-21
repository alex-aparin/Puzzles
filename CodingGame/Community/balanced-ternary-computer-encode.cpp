#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

char convert(const int i, const bool revert)
{
    const char c = i == 2 ? 'T' : (i == 1 ? '1' : '0');
    if (revert)
        return c == 'T' ? '1' : (c == '1' ? 'T' : '0');
    return c;
}

void print_decompose(int num, const bool revert)
{
    list<int> nums;
    while (num >= 3)
    {
        const int r = num % 3;
        num /= 3;
        num += r == 2 ? 1 : 0;
        nums.push_front(r);
    }
    nums.push_front(num);
    if (num == 2)
        nums.push_front(1);
    //  Printing decomposition
    for_each(nums.begin(), nums.end(), 
        [=](const int n){cout << convert(n, revert);});
}

int main()
{
    int DEC;
    cin >> DEC; cin.ignore();
    print_decompose(DEC < 0 ? -DEC : DEC, DEC < 0);
}
