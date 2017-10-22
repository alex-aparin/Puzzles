#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;

int main() 
{
    typedef size_t elem_type;
    typedef vector<elem_type> vec_type;
    typedef set<elem_type> set_type;
    size_t n;
    vec_type prices;
    set_type set_prices;
    elem_type min_loss = numeric_limits<elem_type>::max();
    cin >> n;
    prices.resize(n);
    for (size_t i = 0; i < n; ++i)
    {
        cin >> prices[i];
        set_prices.insert(prices[i]);
    }
    for (size_t i = 0; i + 1 < n; ++i)
    {
        set_type::iterator it = set_prices.find(prices[i]);
        if (it != set_prices.begin())
        {
            set_type::iterator prev_it = it;
            --prev_it;
            min_loss = min(min_loss, *it - *prev_it);
        }
        set_prices.erase(it);
    }
    cout << min_loss << endl;
    return 0;
}
