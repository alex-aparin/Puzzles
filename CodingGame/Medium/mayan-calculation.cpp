#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef std::map<string, int> maya_map_type;
typedef std::vector<string> strings_type;
typedef std::vector<int> maya_num_type;
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int L;
    int H;
    cin >> L >> H; cin.ignore();
    strings_type maya_str_numbers(20);
    for (int i = 0; i < H; i++) {
        string numeral;
        cin >> numeral; cin.ignore();
        for (int k = 0; k < 20; ++k)
            maya_str_numbers[k] += numeral.substr(k * L, L);
    }
    maya_map_type maya_map;
    for (int i = 0; i < 20; ++i)
    {
        maya_map.insert(make_pair(maya_str_numbers[i], i));
    }   
    int S1;
    int s1_n = 0;
    cin >> S1; cin.ignore();
    string s1_num;
    for (int i = 0; i < S1; i++) {
        string num1Line;
        cin >> num1Line; cin.ignore();
        s1_num += num1Line;
    }
    for (int i = 0; i < S1 / H; ++i)
        s1_n = s1_n * 20 + maya_map[s1_num.substr(i * H * L, H * L)];
    int S2;
    long long int s2_n = 0;
    cin >> S2; cin.ignore();
    string s2_num;
    for (int i = 0; i < S2; i++) {
        string num2Line;
        cin >> num2Line; cin.ignore();
        s2_num += num2Line;
    }
    for (int i = 0; i < S2 / H; ++i)
        s2_n = s2_n * 20 + maya_map[s2_num.substr(i * H * L, H * L)];
    string operation;
    cin >> operation; cin.ignore();
    long long int result =0;
    if (operation.at(0) == '+')
        result = s1_n + s2_n;
    if (operation.at(0) == '-')
        result = s1_n - s2_n;
    if (operation.at(0) == '*')
    {
        
        result = s1_n * s2_n;
        cerr << s1_n << endl;
        cerr << s2_n << endl;
        cerr << result << endl;
    }
    if (operation.at(0) == '/')
        result = s1_n / s2_n;
    maya_num_type num;
    do
    {
        num.push_back(result % 20);
        result /= 20;
    }
    while (result != 0);
    reverse(num.begin(), num.end());
    for (size_t i = 0; i < num.size(); ++i)
    {
        const string& num_rep = maya_str_numbers[num[i]];
        for (int j = 0; j < H; ++j)
        {
            cout << num_rep.substr(j * L, L) << endl;
            //cerr << "9999" << num_rep.substr(j * L, L) << endl;
        }
    }
}
