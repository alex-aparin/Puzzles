#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    string line;
    {
        //  Reading line from file
        ifstream myfile("./rosalind_rna.txt");
        if (!myfile.is_open())
            return 1;
        getline (myfile,line);
        myfile.close();
    }
    for_each(line.begin(), line.end(),
        [](const char c)
        {
            const char out_c = c == 'T' ? 'U' : c;
            cout << out_c;
        });
    return 0;
}
