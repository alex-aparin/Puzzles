#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * The code below will read all the game information for you.
 * On each game turn, information will be available on the standard input, you will be sent:
 * -> the total number of visible enemies
 * -> for each enemy, its name and distance from you
 * The system will wait for you to write an enemy name on the standard output.
 * Once you have designated a target:
 * -> the cannon will shoot
 * -> the enemies will move
 * -> new info will be available for you to read on the standard input.
 **/
int main()
{

    // game loop
    while (1) {
        int count; // The number of current enemy ships within range
        cin >> count; cin.ignore();
        string target_enemy_name;
        int target_enemy_distance = 0;
        bool is_init = false;
        for (int i = 0; i < count; i++) {
            string enemy; // The name of this enemy
            int dist; // The distance to your cannon of this enemy
            cin >> enemy >> dist; cin.ignore();
            if ( !is_init )
            {
                is_init = true;
                target_enemy_name = enemy;
                target_enemy_distance = dist;
            }
            else
            {
                if ( target_enemy_distance > dist )
                {
                    target_enemy_name = enemy;
                    target_enemy_distance = dist;
                }
            }
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        
        // To debug: cerr << "Debug messages..." << endl;
        cout << target_enemy_name << endl;
        //cout << "HotDroid" << endl; // The name of the most threatening enemy (HotDroid is just one example)
    }
}
