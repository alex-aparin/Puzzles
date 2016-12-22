#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
        Just for fun - I used diophantine equations to solve task
*/

int gcd(const int a, const int b, int& x, int& y) 
{
	if (a == 0) 
	{
		x = 0; 
		y = 1;
		return b;
	}
	int x1, y1;
	const int d = gcd( b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

typedef pair<int, int> root_type;
typedef vector<root_type> sol_type;
 
int diophantine_solution(const int a, const int b, const int c, root_type& root)
{
    int u, v;
    const int gcd_ab = gcd(a, b, u, v);
    gcd(a / gcd_ab, b / gcd_ab, u, v);
    root.first = c * u / gcd_ab;
    root.second = c * v / gcd_ab;
    return gcd_ab;
}

void invert_roots(bool should_invert, sol_type& sols)
{
    if (should_invert)
    {
        for (size_t i = 0; i < sols.size(); ++i)
            swap(sols[i].first, sols[i].second);
    }
}

sol_type solve(int a, int b, int k, int m)
{
    sol_type sols;
    root_type root;
    const bool invert = m < k;
    cerr << "invert" << invert << endl;
    if (invert)
    {
        swap(a, b);
        swap(k, m);
    }
    const int gcd_ab = diophantine_solution(a, b, m-k, root);
    if ((m-k) % gcd_ab != 0)
        return sols;
    if (root.first >= 0 && root.second >= 0)
    {
        cerr << "DEBUG >=0 >=0" << endl;
        while (root.second > 0)
        {
            root.first += b / gcd_ab;
            root.second -= a / gcd_ab;
        }
        sols.push_back(root);
    }
    else if (root.first >= 0 && root.second <= 0)
    {
        cerr << "DEBUG >=0 <=0" << endl;
        while (root.first - b / gcd_ab >= 0 &&  root.second + a / gcd_ab <= 0)
        {
            root.first -= b / gcd_ab;
            root.second += a / gcd_ab;
        }
        sols.push_back(root);
    }
    else if (root.first <= 0 && root.second >= 0)
    {
        cerr << "DEBUG <=0 >=0" << endl;
        while (root.first <= 0 || root.second >= 0)
        {
            root.first += b / gcd_ab;
            root.second -= a / gcd_ab;
        }
        sols.push_back(root);
    }
    else if (root.first <= 0 && root.second <= 0)
    {   
        cerr << "DEBUG <=0 <=0" << endl;
    }
    invert_roots(invert, sols);
    return sols;
}

bool test_solution(const int i, const int x, const int y, const int a, const int b, const int n)
{
    bool res = false;
    if (x == 0 && y == 0)
        res = true;
    if (x != 0 && a + i < n)
        res = res || test_solution(i + a, x-1, y, a, b, n);
    if (y != 0 && i - b >= 0)
        res = res || test_solution(i - b, x, y-1, a, b, n);
    return res;
}

int main()
{
    int n, a, b, k, m;
    cin >> n >> a >> b >> k >> m; cin.ignore();

    sol_type sols = solve(a, b, k, m);
    cerr << "a b k m n" << endl;
    cerr << a << " " << b << " " << k << " " << m << " " << n << endl;
    cerr << "solutions" << endl;
    for (int i = 0; i < sols.size(); ++i)
        cerr << sols[i].first << "," << sols[i].second << endl;
    if (sols.empty() || !test_solution(k, abs(sols[0].first), abs(sols[0].second), a, b, n))
        cout << "IMPOSSIBLE" << endl;    
    else
        cout << (int)(abs(sols[0].first) + abs(sols[0].second)) << endl;
    
    
}
