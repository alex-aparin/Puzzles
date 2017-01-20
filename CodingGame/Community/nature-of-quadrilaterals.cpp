#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

class Point
{
public:
	Point() : 
		m_x(0), m_y(0)
	{
	}
	Point(const int x, const int y) :
		m_x(x), m_y(y)
	{
	}
	friend istream& operator>>(istream& istr, Point& point)
	{
		istr >> point.m_x >> point.m_y;
		return istr;
	}
	Point operator-(const Point& rhs) const
	{
		return Point(m_x - rhs.m_x, m_y - rhs.m_y);
	}
	int square_len() const
	{
		return m_x * m_x + m_y * m_y;
	}
	int cross_product(const Point& rhs) const
	{
		return m_x * rhs.m_y - m_y * rhs.m_x;
	}
	int dot_product(const Point& rhs) const
	{
		return m_x * rhs.m_x + m_y * rhs.m_y;
	}
private:
	int m_x;
	int m_y;
};



typedef array<Point, 4> quadr_type;

bool is_parallelogram(const quadr_type& quadr)
{
	const bool side_1_is_parallel = (quadr[1] - quadr[0]).cross_product(quadr[2] - quadr[3]) == 0;
	const bool side_2_is_parallel = (quadr[2] - quadr[1]).cross_product(quadr[3] - quadr[0]) == 0;
	return side_1_is_parallel && side_2_is_parallel;
}

bool is_rhombus(const quadr_type& quadr)
{
	bool is_rhombus = true;
	const int init_len = (quadr[1] - quadr[0]).square_len();
	for (int i = 0; is_rhombus && i < 4; ++i)
		is_rhombus = (quadr[(i+1)%4] - quadr[i]).square_len() == init_len;
	return is_rhombus;
}

bool is_rectangle(const quadr_type& quadr)
{
	bool is_rect = true;
	for (int i = 0; is_rect && i < 4; ++i)
		is_rect = (quadr[(i + 1) % 4] - quadr[i]).dot_product(quadr[(i + 2) % 4] - quadr[(i + 1) % 4]) == 0;
	return is_rect;
}

string get_quadr_type(const quadr_type& quadr)
{
	const bool is_rect = is_rectangle(quadr);
	const bool is_rhomb = is_rhombus(quadr);
	if (is_rhomb && is_rect)
		return "square";
	if (is_rhomb)
		return "rhombus";
	if (is_rect)
		return "rectangle";
	if (is_parallelogram(quadr))
		return "parallelogram";
	return "quadrilateral";
}

int main()
{
	int n;
	cin >> n; cin.ignore();
	for (int i = 0; i < n; i++) 
	{
		quadr_type quadr;
		string A;
		string B;
		string C;
		string D;
		cin >> A >> quadr[0] >> B >> quadr[1] >> C >> quadr[2] >> D >> quadr[3]; cin.ignore();
		cout << A << B << C << D << " is a " << get_quadr_type(quadr) << "." << endl;
	}
}
