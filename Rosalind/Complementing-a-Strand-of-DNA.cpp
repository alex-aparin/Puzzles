#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    map<char, char> mapping;
    mapping.insert(make_pair('A', 'T'));
    mapping.insert(make_pair('T', 'A'));
    mapping.insert(make_pair('C', 'G'));
    mapping.insert(make_pair('G', 'C'));
    string line;
    {
        //  Reading line from file
        ifstream myfile("./rosalind_revc.txt");
        if (!myfile.is_open())
            return 1;
        getline (myfile,line);
        myfile.close();
    }
    reverse(line.begin(), line.end());
    for_each(line.begin(), line.end(), [&](const char c){ cout << mapping[c]; });
    return 0;
}
