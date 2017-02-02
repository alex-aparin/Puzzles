#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct Point
{
    int m_x;
    int m_y;
    Point( const int x, const int y) :
        m_x( x ), m_y( y )
    {}
};

Point getTheCentroidOf( const Point& left_top_p, const Point& right_bot_p )
{
    Point result = Point( ( left_top_p.m_x + right_bot_p.m_x ) / 2, ( left_top_p.m_y + right_bot_p.m_y ) / 2 );
    return result;
}
void toUp( Point& source, const Point& target )
{
    source.m_y = target.m_y;
}
void toRight( Point& source, const Point& target )
{
    source.m_x = target.m_x;
}
void toDown( Point& source, const Point& target )
{
    source.m_y = target.m_y;
}
void toLeft( Point& source, const Point& target )
{
    source.m_x = target.m_x;
}
enum BATMAN_DIR
{
    U, 
    UR, 
    R, 
    DR, 
    D, 
    DL, 
    L,
    UL
};

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{

    int W = 4; // width of the building.
    int H = 8; // height of the building.
    cin >> W >> H; cin.ignore();
    int N = 10; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0 = 2;
    int Y0 = 3;
    cin >> X0 >> Y0; cin.ignore();
    Point current_location = Point( X0, Y0 );
    Point left_top_p = Point( 0, 0 );
    Point right_bot_p = Point( W, H );

    // game loop
    while (1) {
        string BOMB_DIR;// the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> BOMB_DIR;cin.ignore();
		const string U_str = string("U");
		const string UR_str = string("UR");
		const string R_str = string("R");
		const string DR_str = string("DR");

		const string D_str = string("D");
		const string DL_str = string("DL");
		const string L_str = string("L");
		const string UL_str = string("UL");
        //cin >> BOMB_DIR; cin.ignore();
        cerr<<"Bomd direction "<<BOMB_DIR<<endl;
        BATMAN_DIR batman_dir;
        if ( BOMB_DIR == U_str  )
            batman_dir = BATMAN_DIR::U;
        if ( BOMB_DIR == UR_str )
            batman_dir = BATMAN_DIR::UR;
        if ( BOMB_DIR == R_str )
            batman_dir = BATMAN_DIR::R;
        if ( BOMB_DIR == DR_str )
            batman_dir = BATMAN_DIR::DR;
        if ( BOMB_DIR == D_str )
            batman_dir = BATMAN_DIR::D;
        if ( BOMB_DIR == DL_str )
            batman_dir = BATMAN_DIR::DL;
        if ( BOMB_DIR ==  L_str )
            batman_dir = BATMAN_DIR::L;
        if ( BOMB_DIR == UL_str )
            batman_dir = BATMAN_DIR::UL;
        
        switch ( batman_dir )
        {
            case BATMAN_DIR::U: 
                toUp( right_bot_p, current_location );
                break;
            case BATMAN_DIR::UR: 
                toUp( right_bot_p, current_location );
                toRight( left_top_p, current_location );
                break;
            case BATMAN_DIR::R: 
                toRight( left_top_p, current_location );
                break;
            case BATMAN_DIR::DR: 
                
                toDown( left_top_p, current_location );
                toRight( left_top_p, current_location );
                cerr << left_top_p.m_x << " " << left_top_p.m_y << endl;
                break;
            case BATMAN_DIR::D: 
                toDown( left_top_p, current_location );
                break;
            case BATMAN_DIR::DL:
                toDown( left_top_p, current_location );
                toLeft( right_bot_p, current_location );
                break;
            case BATMAN_DIR::L: 
                toLeft( right_bot_p, current_location );
            break;
            case BATMAN_DIR::UL:
                toUp( right_bot_p, current_location );
                toLeft( right_bot_p, current_location );
            break;
        }
        
        current_location = getTheCentroidOf( left_top_p, right_bot_p );
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        cout << current_location.m_x << " " << current_location.m_y << endl;
        //cout << "0 0" << endl; // the location of the next window Batman should jump to.
    }
}
