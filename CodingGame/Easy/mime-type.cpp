#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

typedef std::string map_key_type;
typedef std::string map_body_type;
typedef std::map<map_key_type,map_body_type> map_type;
typedef std::vector<std::string> result_type;
using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
 bool validate_name( const string & input_str, size_t dot_pos )
 {
     if ( dot_pos >= 256 )
        return false;
     if ( dot_pos == input_str.length() - 1)
        return false;
    for ( size_t i = 0; i < dot_pos; ++i )
    {
        if ( 'a' <= input_str[i] && input_str[i]  <= 'z' )
            continue;
        if ( 'A' <= input_str[i] && input_str[i]  <= 'Z' )
            continue;
        if ( input_str[i] == '.' )
            continue;
        return false;
    }
    return true;
 }
 bool validate_mime_type( const string& mime_name )
 {
     if ( mime_name.length() > 50 )
        return false;
    for ( size_t i = 0; i < mime_name.length(); ++ i  )
    {
        if ( 'a' <= mime_name[i] && mime_name[i]  <= 'z' )
            continue;
        if ( 'A' <= mime_name[i] && mime_name[i]  <= 'Z' )
            continue;
        if ( '!' <= mime_name[i] && mime_name[i]  <= '@' )
            continue;
        if ( '[' <= mime_name[i] && mime_name[i]  <= '`' )
            continue;
        if ( '{' <= mime_name[i] && mime_name[i]  <= '}' )
            continue;
        if ( '0' <= mime_name[i] && mime_name[i]  <= '9' )
            continue;
        return false;
    }
    return true;
 }
int main()
{
    map_type mime_table;
    result_type answers;
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        for ( size_t i = 0; i < EXT.length(); ++i )
            EXT[i] = toupper(EXT[i]);
        if ( validate_mime_type(MT) )
        mime_table.insert(pair<map_key_type,map_body_type>(EXT,MT));
        //cerr << EXT << ":" << MT << endl;
    }
    cerr << "input" << endl;
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        cerr << FNAME << endl;
        size_t find_answer = string::npos;
        for ( size_t i = 0; i < FNAME.length(); ++i )
        {
            if ( FNAME[i] == '.' )
                find_answer = i;
        }
        if ( find_answer == string::npos ||  !validate_name(FNAME,find_answer))
        {
            answers.push_back( "UNKNOWN" );
            continue;
        }
        string file_ext = FNAME.substr( find_answer + 1 );
        for ( size_t i = 0; i < file_ext.length(); ++i )
            file_ext[i] = toupper(file_ext[i]);
        map_type::iterator it = mime_table.find( file_ext );
        if ( it == mime_table.end() )
            answers.push_back( "UNKNOWN" );
        else
            answers.push_back( it->second );
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    for ( size_t i = 0; i < answers.size(); ++i )
        cout << answers[i] << endl;
}
