#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef map<char,int> letter_map_type;
typedef vector<string> dictionary_type;
letter_map_type letter_cost_map;

void init_letters_costs()
{
    letter_cost_map.clear();
    letter_cost_map.insert(std::pair<char,int>('e',1));
    letter_cost_map.insert(std::pair<char,int>('a',1));
    letter_cost_map.insert(std::pair<char,int>('i',1));
    letter_cost_map.insert(std::pair<char,int>('o',1));
    letter_cost_map.insert(std::pair<char,int>('n',1));
    letter_cost_map.insert(std::pair<char,int>('r',1));
    letter_cost_map.insert(std::pair<char,int>('t',1));
    letter_cost_map.insert(std::pair<char,int>('l',1));
    letter_cost_map.insert(std::pair<char,int>('s',1));
    letter_cost_map.insert(std::pair<char,int>('u',1));
    
    letter_cost_map.insert(std::pair<char,int>('d',2));
    letter_cost_map.insert(std::pair<char,int>('g',2));
    
    letter_cost_map.insert(std::pair<char,int>('b',3));
    letter_cost_map.insert(std::pair<char,int>('c',3));
    letter_cost_map.insert(std::pair<char,int>('m',3));
    letter_cost_map.insert(std::pair<char,int>('p',3));
    
    letter_cost_map.insert(std::pair<char,int>('f',4));
    letter_cost_map.insert(std::pair<char,int>('h',4));
    letter_cost_map.insert(std::pair<char,int>('v',4));
    letter_cost_map.insert(std::pair<char,int>('w',4));
    letter_cost_map.insert(std::pair<char,int>('y',4));
    
    letter_cost_map.insert(std::pair<char,int>('k',5));
    
    letter_cost_map.insert(std::pair<char,int>('j',8));
    letter_cost_map.insert(std::pair<char,int>('x',8));
    
    letter_cost_map.insert(std::pair<char,int>('q',10));
    letter_cost_map.insert(std::pair<char,int>('z',10));
}

int cost_str( const string& str)
{
    int cost = 0;
    for ( size_t i = 0; i < str.size(); ++i )
        cost += letter_cost_map[str[i]];
    return cost;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    init_letters_costs();
    dictionary_type dictionary;
    int N;
    cin >> N; cin.ignore();
    int max_cost = 0;
    for (int i = 0; i < N; i++) {
        string W;
        getline(cin, W);
        dictionary.push_back( W );
    }
    for ( size_t i = 0; i < dictionary.size(); ++i )
        cerr << "str: " << dictionary[i] << " cost : " << cost_str(dictionary[i]) <<endl;
    string LETTERS;
    getline(cin, LETTERS);
    int max_score = 0;
    string answer;
    for ( size_t i = 0; i<dictionary.size(); ++i )
    {
        string copy_str = dictionary[i];
        int current_score = cost_str(copy_str);
        for ( size_t j = 0; j < LETTERS.size(); ++j )
        {
            if (copy_str.empty())
                break;
            size_t pos = copy_str.find(LETTERS[j]);
            if ( pos == string::npos )
                continue;
            copy_str.erase( copy_str.begin() + pos );
        }
        if ( copy_str.empty() && max_score < current_score )
        {
            max_score = current_score;
            answer = dictionary[i];
        }
    }
    cout << answer << endl;
}
