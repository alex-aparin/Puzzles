#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
 typedef long int int_type;
int main()
{
    int n;
    cin >> n; cin.ignore();
    string vs;
    getline(cin, vs);
    cerr << vs << endl;
    std::istringstream is( vs );
    int_type stock_value;
    std::vector<int_type> stock_values;
    while( is >> stock_value ) 
        stock_values.push_back( stock_value );
    int_type maximal_loss = 0;
    int_type max_stock_value = stock_values[0];
    int_type min_stock_value = stock_values[0];
    for ( size_t i = 1; i < stock_values.size(); ++i )
    {
        if ( max_stock_value > stock_values[i] )
            min_stock_value = std::min( min_stock_value, stock_values[i] );
        else
        {
            maximal_loss = std::min( maximal_loss, min_stock_value - max_stock_value );
            max_stock_value = stock_values[i];
            min_stock_value = stock_values[i];
        }
    }
    if ( max_stock_value > min_stock_value )
        maximal_loss = std::min( maximal_loss, min_stock_value - max_stock_value );
        
    cerr << n << endl;    
    cout << maximal_loss << endl;
}
