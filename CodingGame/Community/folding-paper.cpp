#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int get_index(const char c)
{
    const double x = (int)c;
    return round(11.5 * log(x) - 49) + (c == 'R');
}
int main()
{
    string order;
    getline(cin, order);
    string side;
    getline(cin, side);
    
    std::vector<int> layers = {1, 1, 1, 1};
    for (size_t i = 0; i < order.size(); ++i)
    {
        int index = get_index(order[i]);
        layers[(index + 2) % 4] += layers[index];
        layers[(index + 1) % 4] *= 2;
        layers[(index + 3) % 4] *= 2;
        layers[index] = 1;
    }
    cout << layers[get_index(side[0])] << endl;
}