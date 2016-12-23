#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

typedef std::bitset<7> binary_char_type;

string encodeSeriesBits( const bool bit, const int N )
{
    string encoded_bits;
    
    encoded_bits.push_back( '0' );
    if ( bit == false )
        encoded_bits.push_back( '0' );
    encoded_bits.push_back( ' ' );
    for ( int i = 0; i < N; ++i )
        encoded_bits.push_back( '0' );
    encoded_bits.push_back( ' ' );
    return encoded_bits;
}

string getBinaryString( const string& input_str )
{
    string result;
   for ( size_t i = 0; i < input_str.size(); ++i )
   {
        string tmp;
        binary_char_type letter_bin = input_str[i]; 
        for ( int j = 6; j >= 0; --j )
        {
            if ( letter_bin[j] )
                tmp.push_back( '1' );
            else
                tmp.push_back( '0' );
        }
        result.append(tmp);
   }
   return result;
}
string encodeString( const string& input_str )
{
    string bin_input_str = getBinaryString( input_str );
    
    string encoded_string;
    binary_char_type letter_bin = input_str[0]; 
    bool current_bit = letter_bin[6]; 
    int count_bit = 0;
    bool crossed_threshold = false;
    string encoded_str;
   for ( size_t i = 0; i < bin_input_str.size(); ++i )
   {
        if ( current_bit != ( bin_input_str[i] - '0' ) )
            crossed_threshold = true;
        else
           ++count_bit;
        if ( crossed_threshold )
        {
            
            encoded_str.append(encodeSeriesBits( current_bit, count_bit));
            encoded_string.append( encodeSeriesBits( current_bit, count_bit) );
            current_bit = !current_bit;
            count_bit = 1;
            crossed_threshold = false;
        }
   }
   if ( crossed_threshold == false )
    encoded_string.append(encodeSeriesBits( current_bit, count_bit));
   encoded_string.pop_back();
   return encoded_string;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    cout << encodeString(MESSAGE) << endl;
}
