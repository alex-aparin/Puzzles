#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

typedef std::vector<int> vector_type;
typedef std::vector<vector_type> matrix_type;

struct  Point
{
    static void moveFromLeft( Point& current_pos )
    {
        cerr<<"From left"<<endl;
        cerr<<" Cell type "<<current_pos.m_cell_type<<endl;
        switch ( current_pos.m_cell_type )
        {
            case 0: throw "Bad cell";  break;
            case 1: ++current_pos.m_y; break;
            case 2: ++current_pos.m_x; break;
            case 3: throw "Bad cell";  break;
            case 4: throw "Bad cell";  break;
            case 5: ++current_pos.m_y; break;
            case 6: ++current_pos.m_x; break;
            case 7: throw "Bad cell";  break;
            case 8: ++current_pos.m_y; break;
            case 9: ++current_pos.m_y; break;
            case 10: throw "Bad cell"; break;
            case 11: throw "Bad cell"; break;
            case 12: throw "Bad cell"; break;
            case 13: ++current_pos.m_y; break;
        }
    }
    static void moveFromRight( Point& current_pos )
    {
        cerr<<"From right"<<endl;
        cerr<<" Cell type "<<current_pos.m_cell_type<<endl;
        switch ( current_pos.m_cell_type )
        {
            case 0: throw "Bad cell";  break;
            case 1: ++current_pos.m_y; break;
            case 2: --current_pos.m_x; break;
            case 3: throw "Bad cell";  break;
            case 4: ++current_pos.m_y; break;
            case 5: throw "Bad cell";  break;
            case 6: --current_pos.m_x; break;
            case 7: ++current_pos.m_y; break;
            case 8: ++current_pos.m_y; break;
            case 9: throw "Bad cell";  break;
            case 10: throw "Bad cell"; break;
            case 11: throw "Bad cell"; break;
            case 12: ++current_pos.m_y; break;
            case 13: throw "Bad cell";  break;
        }        
    }
    static void moveFromTop( Point& current_pos )
    {
        cerr<<"From Top"<<endl;
        cerr<<" Cell type "<<current_pos.m_cell_type<<endl;
        switch ( current_pos.m_cell_type )
        {
            case 0: throw "Bad cell";  break;
            case 1: ++current_pos.m_y; break;
            case 2: throw "Bad cell";  break;
            case 3: ++current_pos.m_y; break;
            case 4: --current_pos.m_x; break;
            case 5: ++current_pos.m_x; break;
            case 6: throw "Bad cell";  break;
            case 7: ++current_pos.m_y; break;
            case 8: throw "Bad cell";  break;
            case 9: ++current_pos.m_y; break;
            case 10: --current_pos.m_x; break;
            case 11: ++current_pos.m_x; break;
            case 12: throw "Bad cell";  break;
            case 13: throw "Bad cell";  break;
        }        
    }
    int m_x;
    int m_y;
    int m_cell_type;
    Point( ) :
        m_x( 0 ), m_y( 0 ), m_cell_type( 0 )
    {}
    Point( const int x, const int y, const int cell_type ) :
        m_x( x ), m_y( y ), m_cell_type( cell_type )
    {}
    void moveOverMaze( Point& pred_pos )
    {
        Point next_pos = *this;
        //  From right to left
        if ( m_x < pred_pos.m_x )
            moveFromRight( next_pos );
        //  From left to right
        if ( m_x > pred_pos.m_x )
            moveFromLeft( next_pos );
        //  From top to down
        if ( m_y > pred_pos.m_y )
            moveFromTop( next_pos );
        pred_pos.m_x = m_x;
        pred_pos.m_y = m_y;
        m_x = next_pos.m_x;
        m_y = next_pos.m_y;
    }
};

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int W; // number of columns.
    int H; // number of rows.
    matrix_type matrix;
    
    cin >> W >> H; cin.ignore();
    for (int i = 0; i < H; i++) {
        vector_type raw_input;
        string LINE; // represents a line in the grid and contains W integers. Each integer represents one room of a given type.
        getline(cin, LINE);
        istringstream is( LINE );
        string word;
        while ( is >> word ) 
            raw_input.push_back( stoi( word ) );
        matrix.push_back( raw_input );
    }
    int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
    cin >> EX; cin.ignore();
    bool first_step = true;
    Point pred_pos;
    Point current_pos;
    // game loop
    while (1) {
        int XI;
        int YI;
        string POS;
        cin >> XI >> YI >> POS; cin.ignore();
        if ( first_step == true )
        {
            first_step = false;
            pred_pos.m_x = XI;
            pred_pos.m_y = YI;
            pred_pos.m_cell_type = 0;   //  some value
            if ( POS == string("TOP") )
                --pred_pos.m_y;
            if ( POS == string("RIGHT") )
                ++pred_pos.m_x;
            if ( POS == string("LEFT") )
                --pred_pos.m_x;
        }
        current_pos = Point( XI, YI, matrix[YI][XI]);
        current_pos.moveOverMaze( pred_pos );

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << current_pos.m_x << " " << current_pos.m_y << endl; // One line containing the X Y coordinates of the room in which you believe Indy will be on the next turn.
    }
}
