#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

string build_concesus(const vector<string>& dna_strs, const size_t cols,
                        const char patterns[4], map<char, vector<int>>& occurs)
{
    string res(cols, '_');
    for (size_t j = 0; j < cols; ++j)
    {
        for (size_t i = 0; i < dna_strs.size(); ++i)
            for (int k = 0; k < 4; ++k)
                occurs.at(patterns[k])[j] += patterns[k] == dna_strs[i][j] ? 1 : 0;
        char max_char = patterns[0];
        for (int k = 1; k < 4; ++k)
            if (occurs.at(max_char)[j] < occurs.at(patterns[k])[j])
                max_char = patterns[k];
        res[j] = max_char;
    }
    return res;
}

int main()
{
    vector<string> dna_strs;
    size_t cols = 0;
    {
        ifstream myfile("./rosalind_cons.txt");
        if (!myfile.is_open())
            return 1;
        dna_strs.reserve(10);
        string temp;
        bool res = getline(myfile, temp);
        while (res)
        {
            string inp_str;
            while ((res = getline(myfile, temp)) && temp[0] != '>')
                inp_str += temp;
            dna_strs.push_back(inp_str);
        }
        cols = dna_strs.back().size();
        myfile.close();
    }
    map<char, vector<int>> occrs;
    const char chs[4] = {'A', 'C', 'G', 'T'};
    for (int i = 0; i < 4; ++i)
        occrs.insert(make_pair(chs[i], vector<int>(cols, 0)));
    cout << build_concesus(dna_strs, cols, chs, occrs) << endl;
    for (int i = 0; i < 4; ++i)
    {
        const vector<int>& vals = occrs.at(chs[i]);
        cout << chs[i] << ":";
        for_each(vals.begin(), vals.end(), [](const int num){cout << " " << num;});
        cout << endl;
    }
    return 0;
}
