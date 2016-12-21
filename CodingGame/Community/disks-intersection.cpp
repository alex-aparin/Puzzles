#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int x1;
    int y1;
    int r1;
    cin >> x1 >> y1 >> r1; cin.ignore();
    int x2;
    int y2;
    int r2;
    cin >> x2 >> y2 >> r2; cin.ignore();
    cout << std::fixed << std::setprecision(2);
    const double d = sqrt(pow(x1-x2, 2.0) + pow(y1-y2, 2.0));
    if (r1 + r2 <= d)
    {
        cout << 0.0 << endl;
        return 0;
    }
    if (d <= r1 && r2 <= r1)
    {
      cout << M_PI * r2 * r2 << endl;
      return 0;
    }
    if (d <= r2 && r1 <= r2)
    {
      cout << M_PI * r1 * r1 << endl;
      return 0;
    }
    const double ar = r1 * r1 * acos((d*d + r1*r1 - r2*r2)/(2*d*r1)) + 
                      r2 * r2 * acos((d*d + r2*r2 - r1*r1)/(2*d*r2)) -
                      0.5 * sqrt((-d + r1 + r2) * (d + r1 - r2) * (d - r1 + r2) * (d + r1 + r2));
    cout << ar << endl;
}
