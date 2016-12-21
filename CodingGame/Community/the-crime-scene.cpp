#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point
{
    Point() : x(0.0), y(0.0)
    {
    }
    Point(const int _x, const int _y) : 
        x(_x), y(_y)
    {
    }
    Point operator-(const Point& other) const
    {
        return Point(x - other.x, y - other.y);
    }
    bool operator==(const Point& other) const
    {
        return x == other.x && y == other.y;
    }
    double cross_product(const Point& other) const
    {
        return x * other.y - y * other.x;
    }
    double angle(void) const
    {
        return atan2(y, x);
    }
    double module(void) const
    {
        return sqrt(x * x + y * y);
    }
    int x;
    int y;
};

struct PolarSorter
{
    PolarSorter(const Point& _base_point) : 
        base_point(_base_point)
    {
    }
    bool operator()(const Point& lhs, const Point& rhs) const
    {
        if (lhs == base_point)
            return true;
        if (rhs == base_point)
            return false;
        return (lhs - base_point).angle() < (rhs - base_point).angle();
    }
    Point base_point;
};

typedef vector<Point> poly_type;

double compute_perimeter(const poly_type& input_poly)
{
    double res = 0.0;
    for (size_t i = 0; i < input_poly.size(); ++i)
        res += (input_poly[i]-input_poly[(i+1)%input_poly.size()]).module();
    return res;
}

poly_type build_convex_hull(const poly_type& input_poly)
{
    if (input_poly.size() < 3)
        return input_poly;
    poly_type convex_poly;
    convex_poly.reserve(input_poly.size());
    poly_type kernel_poly = input_poly;
    sort(kernel_poly.begin(), kernel_poly.end(),
        PolarSorter(*min_element(input_poly.begin(),input_poly.end(), [](const Point& lhs, const Point& rhs){return lhs.x < rhs.x;})));
    convex_poly.push_back(kernel_poly[0]);
    convex_poly.push_back(kernel_poly[1]);
    for (size_t i = 2; i < kernel_poly.size(); ++i)
    {
        for (;;)
        {
            const size_t cnv_size = convex_poly.size();
            const Point& first_vector = kernel_poly[i] - convex_poly[cnv_size-1];
            const Point& second_vector = convex_poly[cnv_size-2] - convex_poly[cnv_size-1];
            if (first_vector.cross_product(second_vector) > 0.0)
                break;
            convex_poly.pop_back();
        }
        convex_poly.push_back(kernel_poly[i]);
    }
    return convex_poly;
}

int main()
{
    const double off_radius = 3.0;
    const double roll_length = 5.0;
    int N;
    cin >> N; cin.ignore();
    poly_type polygon;
    polygon.reserve(N);
    for (int i = 0; i < N; i++) 
    {
        int X;
        int Y;
        cin >> X >> Y; cin.ignore();
        polygon.push_back(Point(X, Y));
    }
    
    const double perimeter = compute_perimeter(build_convex_hull(polygon)) + 2 * M_PI * off_radius;
    const int rolls_count = ceil(perimeter / roll_length);
    cout << rolls_count << endl;
}
