#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long int int_type;
typedef long int result_type;
typedef std::pair<int_type,int_type> point_type;
typedef std::vector<point_type> buildings_type;

buildings_type  buildings;
result_type positive_sum_y = 0;
result_type negative_sum_y = 0;

const int_type getCablesLength( const int_type level_y )
{
    int_type cables_length = 0;
    for ( size_t i = 0;  i < buildings.size(); ++i )
        cables_length += abs( buildings[i].second - level_y );
    return cables_length;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N;
    cin >> N; cin.ignore();
    int_type west_most_x = 0;
    int_type east_most_x = 0;
    result_type middle_y = 0;
    for (int i = 0; i < N; i++) {
        int_type X;
        int_type Y;
        cin >> X >> Y; cin.ignore();
        west_most_x = i == 0 ? X : std::min( west_most_x, X );
        east_most_x = i == 0 ? X : std::max( east_most_x, X );
        buildings.push_back( point_type( X, Y ) );
        middle_y += Y;
    }
    middle_y /=  N;
    int_type min_y = 0;
    int_type max_y = 0;
    int_type mid_y = 0;
    bool min_y_b = false;
    bool max_y_b = false;
    bool mid_y_b = false;
    
    for ( size_t i = 0; i < buildings.size(); ++i )
    {
        if ( buildings[i].second < middle_y )
        {
            min_y = min_y_b == false ? buildings[i].second : std::max( buildings[i].second, min_y );
            min_y_b = true;
        }
        if ( buildings[i].second == middle_y )
        {
            mid_y = buildings[i].second;
            mid_y_b = true;
        }
        if ( middle_y < buildings[i].second   )
        {
            max_y = max_y_b == false ? buildings[i].second : std::min( buildings[i].second, max_y );
            max_y_b = true;
        }
    }
    int_type cables_length = getCablesLength( min_y );
    cables_length = std::min( cables_length, getCablesLength( max_y ));
    cables_length = std::min( cables_length, getCablesLength( mid_y ));
    cout << cables_length + ( east_most_x - west_most_x ) << endl;
}
