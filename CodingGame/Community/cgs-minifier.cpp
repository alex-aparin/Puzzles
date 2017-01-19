#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string clear_formatting(const string& str)
{
	string new_str;
	new_str.reserve(str.size());
	bool should_remove_formatting = true;
	for (size_t i = 0; i < str.size(); ++i)
	{
		should_remove_formatting = str[i] == '\'' ? !should_remove_formatting : should_remove_formatting;
		if (should_remove_formatting && (str[i] == ' ' || str[i] == '\t'))
			continue;
		new_str.push_back(str[i]);
	}
	return new_str;
}

string minify_vars(const string& str)
{
	string new_str;
	map<string, string> vars;
	char current_name = 'a';
	bool should_process = true;
	bool should_process_var = false;
	string temp_str;
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!should_process || !should_process_var && str[i] != '$')
		{
			new_str.push_back(str[i]);
			should_process = str[i] == '\'' ? !should_process : should_process;
		}
		if (should_process && (str[i] == '$' || should_process_var))
		{
			temp_str.push_back(str[i]);
			should_process_var = str[i] == '$' ? !should_process_var : should_process_var;
			if (!should_process_var)
			{
				if (vars.find(temp_str) == vars.end())
					vars.insert(make_pair(temp_str, "$" + string(1, current_name++) + "$"));
				new_str += vars.at(temp_str);
				temp_str.clear();
			}
		}
	}
	return new_str;
}

int main()
{
	int N;
	string minified_str;
	cin >> N; cin.ignore();
	for (int i = 0; i < N; i++) {
		string CGSContent;
		getline(cin, CGSContent);
		minified_str += CGSContent;
	}
	minified_str = clear_formatting(minified_str);
	minified_str = minify_vars(minified_str);
	cout << minified_str << endl;
}
