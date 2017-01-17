#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void print_choice(const string& str, int& pos, const int choice_id)
{
    vector<string> choices(1, string());
    for (++pos; pos < str.size() && str[pos] != ')'; ++pos)
    {
        if (str[pos] == '|')
            choices.push_back(string());
        else
            choices.back().push_back(str[pos]);
    }
    cout << choices[choice_id % choices.size()];
}

int main()
{
    int N;
    cin >> N; cin.ignore();
    string out_line;
    int choice_id = 0;
    for (int i = 0; i < N; i++) 
    {
        string line;
        getline(cin, line);
        out_line += line + "\n";
    }
    for (int i = 0; i < out_line.size(); ++i)
    {
        if (out_line[i] == '(')
            print_choice(out_line, i, choice_id++);
        else
            cout << out_line[i];
    }
}
