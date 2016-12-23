#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


struct Point
{
    int m_x;
    int m_y;
    Point() : m_x(0), m_y(0) {}
    Point(const int x, const int y) : m_x(x), m_y(y) {}
};
double sqr(const double x)
{
    return x * x;
}
double distance(const Point& a, const Point& b)
{
    return sqrt(sqr(a.m_x - b.m_x) + sqr(a.m_y - b.m_y));
}
typedef std::vector<Point> landscape_type;

void compute_nearest_location(const landscape_type& landscape, const Point& shattle_pos, Point& pos, int& width)
{
    bool first_it = true;
    double nearest_distance;
    for (int i = 1; i < landscape.size(); ++i)
    {
        if (landscape[i-1].m_y != landscape[i].m_y)
            continue;
        const Point& current_pos = landscape[i-1];
        const int current_width  = landscape[i].m_x - landscape[i-1].m_x;
        const double current_distance = distance(shattle_pos, Point(current_pos.m_x + current_width/2, current_pos.m_y));
        if (current_width < 0)
        {
            cerr << "Bad landscape!" << endl;
            exit(-1);
        }
        if (first_it == true)
        {
            first_it = false;
            pos = current_pos;
            width = current_width;
            nearest_distance = current_distance;
        }
        else if (current_distance < nearest_distance)
        {
            pos = current_pos;
            width = current_width;
            nearest_distance = current_distance;
        }
    }
    if (first_it)
    {
      cerr << "Bad landscape!" << endl;
            exit(-1);   
    }
}
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N; // the number of points used to draw the surface of Mars.
    cin >> N; cin.ignore();
    landscape_type lanscape(N);
    for (int i = 0; i < N; i++) {
        int LAND_X; // X coordinate of a surface point. (0 to 6999)
        int LAND_Y; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> LAND_X >> LAND_Y; cin.ignore();
        lanscape[i] = Point(LAND_X, LAND_Y);
    }
    
    bool first_it = true;
    Point start_pos;
    int nearest_width;
    Point end_pos;
    // game loop
    while (1) {
        int X;
        int Y;
        int HS; // the horizontal speed (in m/s), can be negative.
        int VS; // the vertical speed (in m/s), can be negative.
        int F; // the quantity of remaining fuel in liters.
        int R; // the rotation angle in degrees (-90 to 90).
        int P; // the thrust power (0 to 4).
        cin >> X >> Y >> HS >> VS >> F >> R >> P; cin.ignore();
        
        if (first_it)
        {
            first_it = false;
            
            compute_nearest_location(lanscape, Point(X, Y), start_pos, nearest_width);        
            end_pos = Point(start_pos.m_x + nearest_width / 2, start_pos.m_y);
        }
        if (end_pos.m_x + nearest_width < X)
        {
            if (R <= 0)
                cout << R + 15 << " " << P << endl;
            else if (R > 45)
                cout << R - 15 << " " << P << endl;
            else
                cout << R - 0 << " " << P << endl;
            continue;
        }
        else if (end_pos.m_x> X)
        {
            if (R >= 0)
                cout << R - 15 << " " << P << endl;
            else if (R < -45)
                cout << R + 15 << " " << P << endl;
            else
                cout << R - 0 << " " << P << endl;
            continue;
        }
        if (R > 15)
            R -= 15;
        else if (R < 0)
            R += 15;
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        if (end_pos.m_y == Y)
            cout << R << " 4" << endl;
        else if (Y - end_pos.m_y < 1000)
        {
            cerr << "FUCK" << endl;
            cout << R << " 4" << endl;
        }
        else
            cout << R << " 3" << endl; // R P. R is the desired rotation angle. P is the desired thrust power.
    }
}
