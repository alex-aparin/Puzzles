#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef std::vector<int> int_vector;
typedef std::vector<int_vector> conway_seq_type;

conway_seq_type  conway_seq;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
 void buildConwaySeq( const int number_end_line, const int R )
 {
     conway_seq.resize( number_end_line );
     int_vector cur_seq;
     cur_seq.push_back(R);
     conway_seq[0] = cur_seq;
     for ( int i = 1; i < number_end_line; ++i )
     {
         cur_seq.clear();
         int whole_number = conway_seq[i-1][0];
         int repeat_count_number = 1;
         for ( size_t j = 1; j < conway_seq[i-1].size(); ++j )
         {
             if ( whole_number != conway_seq[i-1][j] )
             {
                cur_seq.push_back( repeat_count_number );
                cur_seq.push_back( whole_number );
                whole_number = conway_seq[i-1][j];
                repeat_count_number = 1;
             }
             else
                ++repeat_count_number;
         }
         //if ( repeat_count_number == 1 )
         {
            cur_seq.push_back( repeat_count_number );
            cur_seq.push_back( whole_number );
         }
         conway_seq[i] = cur_seq;
     }
 }
 
 void printLineOfConwaySeq( const int line_number )
 {
     for ( size_t i = 0; i < conway_seq[line_number-1].size(); ++i )
     {
         if ( i != 0 )
            cout << ' ';
         cout << conway_seq[line_number-1][i];
     }
    cout << endl;
 }
 
int main()
{
    int R;
    cin >> R; cin.ignore();
    int L;
    cin >> L; cin.ignore();
    /*
    L = 3;
    R = 1;
    */
    buildConwaySeq( L, R );
    printLineOfConwaySeq( L );
}
