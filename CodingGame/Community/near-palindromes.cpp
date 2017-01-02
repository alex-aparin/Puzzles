#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_palindrom(const string& str)
{
    bool res = true;
    for (size_t i = 0; i < str.size() / 2; ++i) 
        res = res && (str[i] == '_' || str[str.size() - i - 1] == '_' || str[i] == str[str.size() - i - 1]);
    return res;
}

bool is_rep_palindrom(const string& str)
{
    int diff_count = 0;
    for (size_t i = 0; diff_count < 2 && i < str.size() / 2; ++i)
        diff_count += str[i] == str[str.size() - i - 1] ? 0 : 1;
    return diff_count < 2;
}

bool is_near_palindrom(const string& test_str)
{
    string str = "_" + test_str;
    bool res = is_palindrom(str);
    for (size_t i = 0; !res && i < test_str.size(); ++i)
    {
        swap(str[i], str[i+1]);
        res = is_palindrom(str) || is_rep_palindrom(test_str);
    }
    return res;
}

int main()
{
    int N;
    cin >> N; cin.ignore();
    string res;
    for (int i = 0; i < N; i++) {
        string word;
        getline(cin, word);
        res.push_back(is_near_palindrom(word) ? '1' : '0');
    }
    cout << res << endl;
}
