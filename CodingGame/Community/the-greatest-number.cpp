#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <type_traits>

using namespace std;

int main()
{
	int N;
	string input;
	vector<int> numbers;
	bool is_negatif = false;
	bool is_real = false;
	cin >> N; cin.ignore();
	getline(cin, input);
	numbers.reserve(N);
	for (size_t i = 0; i < input.size(); ++i)
	{
	    if (input[i] == ' ')
	        continue;
		is_negatif = is_negatif || (input[i] == '-');
		is_real = is_real || (input[i] == '.');
		if ('0' <= input[i] && input[i] <= '9')
			numbers.push_back(input[i] - '0');
	}
	{
	    std::function<bool(int, int)> func = less<int>();
	    if (!is_negatif)
		    func = greater<int>();
	    sort(numbers.begin(), numbers.end(), func);
	}
	while (is_real && is_negatif && numbers.size() != 1 && numbers.back() == 0)
	    numbers.pop_back();
	if (numbers.front() == numbers.back() && numbers.front() == 0)
	    cout << 0 << endl;
	else
	{
    	if (is_negatif)
    	    cout << '-';
    	for (size_t i = 0; i < numbers.size(); ++i)
    	{
    	    if (is_real && !is_negatif && i + 1 == numbers.size())
    	    {
    	        if (numbers.back() != 0)
    	            cout << '.';
    	        else
    	            break;
    	    }
    	    cout << numbers[i];
    	    if (is_real && is_negatif && i == 0)
    	        cout << '.';
    	}
    	cout <<  endl;
	}
}
