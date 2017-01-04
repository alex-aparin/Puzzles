#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N; cin.ignore();
    vector<string> road_map;
    string XthenCOMMANDS;
    getline(cin, XthenCOMMANDS);
    for (int i = 0; i < N; i++) {
        string RthenROADPATTERN;
        getline(cin, RthenROADPATTERN);
        //  Parse road patterns
        string temp;
        stringstream strstream(RthenROADPATTERN);
        getline(strstream, temp, ';');
        const int R = stoi(temp);
        getline(strstream, temp, ';');
        for (int i = 0; i < R; ++i)
            road_map.push_back(temp);
    }
    {
        //  Parse commands
        stringstream strstream(XthenCOMMANDS);
        string temp;
        getline(strstream, temp, ';');
        int car_x = stoi(temp);
        int car_y = -1;
        while (getline(strstream, temp, ';'))
        {
            const char dir = temp.back();
            temp.pop_back();
            const int steps = stoi(temp);
            const int x_off = dir == 'S' ? 0 : (dir == 'L' ? -1 : 1);
            for (int i = 0; car_y + 1 < road_map.size() && i < steps; ++i)
            {
                ++car_y;
                car_x += x_off;
                road_map[car_y][car_x - 1] = '#';            
            }
        }
    }
    for_each(road_map.begin(), road_map.end(), [](const string& str){cout << str << endl;});
}
