#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

int main()
{
    int hamm_distance = 0;
    {
        ifstream myfile("./rosalind_hamm.txt");
        if (!myfile.is_open())
            return 1;
        string str1;
        string str2;
        getline(myfile, str1);
        getline(myfile, str2);
        for (size_t i = 0; i < str1.size(); ++i)
            hamm_distance += (str1[i] == str2[i]) ? 0 : 1;
        myfile.close();
    }
    cout << hamm_distance << endl;
    return 0;
}
