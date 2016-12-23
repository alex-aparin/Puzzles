#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//  The main idea of solution 
//  We use the Bresenham's method to find the sorter distance to light location
typedef std::pair<int, int> point_type;

std::vector<point_type> getVerticesOfLine( const point_type& thor_location, const point_type& light_location )
{
    std::vector<point_type> line_Bresenhams;
    point_type thor_location_mod = thor_location;
    point_type light_location_mod = light_location;
    const bool steep = 
            abs( thor_location_mod.second - light_location_mod.second) 
            >
            abs( thor_location_mod.first - light_location_mod.first);
    if ( steep )
    {
		std::swap( thor_location_mod.first, thor_location_mod.second );
		std::swap( light_location_mod.first, light_location_mod.second );
    }
    const bool left_to_right = thor_location_mod.first < light_location_mod.first;
    const bool bottom_to_top = thor_location_mod.second < light_location_mod.second;
    //cerr <<" left to right"<< left_to_right << endl;
    //cerr <<" bottom_to_top"<< bottom_to_top << endl;
    int x = thor_location_mod.first;
	int y = thor_location_mod.second;
	const float tan_slope =
			1.0 * abs( light_location_mod.second - thor_location_mod.second )
			/
			abs( light_location_mod.first - thor_location_mod.first );
	float error_dy = 0;
    do
    {
		line_Bresenhams.push_back( point_type( steep ? y : x, steep ? x : y ) );
		error_dy += tan_slope;
		if ( error_dy > 0.5f )
		{
			error_dy -= 1;
			y +=  bottom_to_top == true ? 1 : -1;   
		}
        x +=  left_to_right == true ? 1 : -1;   
    }
    while ( x != light_location_mod.first );
    line_Bresenhams.push_back( light_location );
	return line_Bresenhams;
}


/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int LX; // the X position of the light of power
    int LY; // the Y position of the light of power
    int TX; // Thor's starting X position
    int TY; // Thor's starting Y position
    cin >> LX >> LY >> TX >> TY; cin.ignore();
    std::vector<point_type> line_vertices = getVerticesOfLine( point_type( TX, TY ), point_type(LX, LY) );
    int count = 1;
    // game loop
    while (1) {
        int E; // The level of Thor's remaining energy, representing the number of moves he can still make.
        cin >> E; cin.ignore();
        point_type nearest_vertex = line_vertices[count++];
        string next_step;
        if ( nearest_vertex.second > TY )
            next_step.append( "S" );
        if ( nearest_vertex.second < TY )
            next_step.append( "N" );
        if ( nearest_vertex.first > TX )
            next_step.append( "E" );
        if ( nearest_vertex.first < TX )
            next_step.append( "W" );
        TX = nearest_vertex.first;
        TY = nearest_vertex.second;
        
            
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << next_step << endl; // A single line providing the move to be made: N NE E SE S SW W or NW
        cerr << nearest_vertex.first <<" "<< nearest_vertex.second<< endl;
        
    }
    line_vertices.clear();
}
