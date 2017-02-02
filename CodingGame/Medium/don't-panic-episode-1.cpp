#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Clone
{
    int m_clone_floor; // floor of the leading clone
    int m_clone_pos; // position of the leading clone on its floor
    string m_direction; // direction of the leading clone: LEFT or RIGHT
};

typedef std::vector<int> elevators_type;
typedef std::vector<Clone> clones_type;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int nbFloors; // number of floors
    int width; // width of the area
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    
    
    cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
    elevators_type elevators;
    elevators.resize(nbElevators);
    clones_type    clones;
    for (int i = 0; i < nbElevators; ++i) {
        int m_elevator_floor;
        int m_elevator_pos;
        cin >> m_elevator_floor >> m_elevator_pos; cin.ignore();
        elevators[m_elevator_floor ] = m_elevator_pos;
        cerr<<m_elevator_floor<<"  "<<m_elevator_pos<<endl;
    }
    bool make_step = true;
    int current_floor = 0;
    // game loop
    while (1) {
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> cloneFloor >> clonePos >> direction; cin.ignore();
        if ( cloneFloor == -1 )
        {
             cout << "WAIT" << endl;
            continue;
        }
        const bool does_stop_leading_clone = ( cloneFloor == current_floor );
        const int goal_position = ( cloneFloor == exitFloor ? 
                                    exitPos : 
                                    elevators[cloneFloor] );
        cerr<<goal_position<<"clone "<<clonePos<<endl;
        if ( does_stop_leading_clone )
        {
            ++current_floor;
            const bool left_direction = (direction[0] == 'L');
            cerr<<"Current direction "<<left_direction<<endl;
            string result = string("WAIT");;
            if ( left_direction )
            {
                if ( clonePos < goal_position   )
                    result = string("BLOCK");
            }
            else
            {
                if ( goal_position <  clonePos )
                    result = string("BLOCK");
            }
            cout<<result<<endl;
            
        }
        else
            cout << "WAIT" << endl;
    }
}
