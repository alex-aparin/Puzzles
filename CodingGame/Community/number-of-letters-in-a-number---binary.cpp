#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long num_type;
typedef map<num_type, num_type> cache_type;

num_type compute_number(cache_type& cache, const vector<int>& lengths, const num_type num)
{
    if (num / 2 == 0)
        return lengths[num];
    cache_type::iterator loc = cache.find(num);
    if (loc != cache.end())
        return loc->second;
    loc = cache.insert(make_pair(num, lengths[num % 2] + compute_number(cache,lengths, num / 2))).first;
    return loc->second;
}

int main()
{
    cache_type cache;
    const vector<int> lengths = {4, 3}; 
    num_type start;
    num_type n;
    cin >> start >> n; cin.ignore();
    for (; n != 0; --n)
    {
        const num_type num = start;
        start = compute_number(cache, lengths, start);
        if (num == start)
            break;
    }
    cout << start << endl;
}
