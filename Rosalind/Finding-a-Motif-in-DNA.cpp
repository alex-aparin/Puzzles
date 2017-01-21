#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

bool is_substring(const string& src, const size_t pos, const string& pattern)
{
    bool res = pos + pattern.size() < src.size();
    for (size_t i = pos; res && i < pos + pattern.size(); ++i)
        res = src[i] == pattern[i - pos];
    return res;
}

int main()
{
    string source;
    string pattern;
    {
        ifstream myfile("./rosalind_subs.txt");
        if (!myfile.is_open())
            return 1;
        getline(myfile, source);
        getline(myfile, pattern);
        myfile.close();
    }
    for (size_t i = 0; i < source.size(); ++i)
        if (is_substring(source, i, pattern))
            cout << i + 1 << " ";
    return 0;
}
