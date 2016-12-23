// Read inputs from stdin. Write outputs to stdout.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
    std::vector<int> strengths;
	for (int i = 0; i < n; i++) 
	{
	    int tmp = 0;
	    cin >> tmp;
	    strengths.push_back(tmp);
	}
	if ( n == 1 ){
	    cout << "0" << endl;
	    return 0;
	}
	std::sort( strengths.begin(), strengths.end() );
	int D = strengths[1] - strengths[0];
	for ( int i = 1; i < n; ++i )
	    if ( D > strengths[i] - strengths[i-1] )
	        D = strengths[i] - strengths[i-1];
	cout << D << endl;
	
	return 0;
}
