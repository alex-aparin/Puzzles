#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void perform_eqyptian_mult(int a, int b)
{
	cout << a << " * " << b << endl;
	vector<int> remains;
	while (b != 0)
	{
		if (b % 2 != 0)
		{
			remains.push_back(a);
			b -= 1;
		}
		else
		{
		    b /= 2;
		    a *= 2;
		}
		cout << "= " << a << " * " << b;
		for (size_t i = 0; i < remains.size(); ++i)
			cout << " + " << remains[i];
		cout << endl;
	}
	cout << "= " << accumulate(remains.begin(), remains.end(), 0) << endl;
}

int main()
{
	int a;
	int b;
	cin >> a >> b; cin.ignore();
	if (a < b)
		swap(a, b);
	perform_eqyptian_mult(a, b);
}
