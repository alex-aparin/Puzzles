#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef std::vector<string> ascii_art_type;
struct MapKeyValue
{
    int m_character_id;
    ascii_art_type m_character_rep;
    MapKeyValue( const int  character_id, const ascii_art_type& character_rep ) :
        m_character_id( character_id ), m_character_rep( character_rep )
    {}
    const bool operator<( const MapKeyValue& rhs ) const
    {
        return (m_character_id < rhs.m_character_id);
    }
};

typedef std::map<char, ascii_art_type> ascii_map_type;

void fillRepresentation( ascii_art_type& character_representation, const ascii_art_type& ascii_art, const int W, const int H, const int character_offset )
{
    for ( size_t i = 0; i < H; ++i )
    {
        string current_str;
        for ( size_t j = W * character_offset; j < W * ( character_offset + 1 ); ++j )
        {
            current_str.push_back( ascii_art[i][j] );
        }
        character_representation[i] = current_str;
    }
}

void classify( ascii_map_type& ascii_map, const ascii_art_type& ascii_art, const int W, const int H)
{

    
    const int count_of_characters = 27;
    //  Parser the input the a-z characters
    int character_id = 0;
    for ( ; character_id < count_of_characters; ++character_id )
    {
        ascii_art_type character_representation;
        string default_string = string(W, '+' );
        for ( int i = 0; i < H; ++i )
            character_representation.push_back(default_string);
        fillRepresentation( character_representation, ascii_art, W, H, character_id );
        ascii_map.insert(std::pair<char,ascii_art_type>( 
                        character_id == count_of_characters - 1? 
                        '?'
                        : 
                        'A' + character_id, character_representation 
                    ) 
            );
    }
}

void convertTextToAsciiArt( const string& text, ascii_art_type& output_text, ascii_map_type& ascii_map, const int W, const int H)
{
    string default_string;
    output_text.clear();
    for ( size_t i = 0; i < H; ++i )
        output_text.push_back(default_string);
    for ( size_t letter_it = 0; letter_it < text.size(); ++letter_it )
    {
        const bool is_letter =  ( ascii_map.find(toupper(text[letter_it])) != ascii_map.end() );
        for ( size_t i = 0; i < H; ++i )
        {
            const string& current_text = is_letter == true 
                    ? 
                    ascii_map[toupper(text[letter_it])][i]
                    :
                    ascii_map['?'][i];
            output_text[i].append( current_text );
        }
    }
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    ascii_art_type output_text;
    ascii_art_type ascii_art;
    ascii_map_type ascii_map;
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);
        ascii_art.push_back( ROW );
    }
    classify( ascii_map, ascii_art, L, H );
    convertTextToAsciiArt( T, output_text, ascii_map, L, H );
    // Write an action using cout. DON'T FORGET THE "<< endl"
    cerr << T <<endl;
    cerr <<"Size of map "<<ascii_map.size()<<endl;
    for ( size_t i = 0; i < H; ++i )
        cout<<output_text[i]<<endl;
}
