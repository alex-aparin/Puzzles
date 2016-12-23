#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
typedef std::vector<int> temperatures_type;
typedef std::vector<string> str_number_type;

void splitIntoNumbers( const string& input_str,  str_number_type& numbers_str )
{
    string current_number;
    for ( size_t i = 0; i < input_str.size(); ++i )
    {
        if ( input_str[i] == ' ' && current_number.empty() != true )
        {
            numbers_str.push_back( current_number );
            current_number.clear();
        }
        if ( input_str[i] != ' ' )
            current_number.push_back( input_str[i] );
    }
	if ( current_number.empty() != true  )
		numbers_str.push_back( current_number );
}

void recognizeNumbers( const str_number_type& numbers_str, temperatures_type& temperatures )
{
	for ( size_t i = 0; i < numbers_str.size(); ++i )
		temperatures[i] = atoi(numbers_str[i].c_str());
}

temperatures_type getParsedTemperatures( const string& input_str, const int N )
{
    temperatures_type   temperatures = temperatures_type(N);
    str_number_type     numbers_str  = str_number_type();
    if  ( N == 0 )
        return temperatures;
    splitIntoNumbers( input_str,  numbers_str );
    recognizeNumbers( numbers_str, temperatures );
    return temperatures;
}

struct NearestOrder
{
    static bool compare( const int lhs, const int rhs )
    {
        if ( abs(lhs) == abs(rhs) )
		{
			if ( lhs == rhs )
				return false;
			else
				return lhs > 0;
		}
        return (abs(lhs) < abs(rhs));
    }
};

int getClosestToZero(const temperatures_type& temperatures)
{
	return *std::min_element( temperatures.begin(), temperatures.end(), &NearestOrder::compare);
}
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N; // the number of temperatures to analyse
    cin >> N; cin.ignore();
    string TEMPS; // the N temperatures expressed as integers ranging from -273 to 5526
    getline(cin, TEMPS);
    temperatures_type temperatures = getParsedTemperatures( TEMPS, N );
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    if ( temperatures.empty() )
        cout<<0<<endl;
    else
        cout<<getClosestToZero(temperatures)<<endl;
}
