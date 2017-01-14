#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int mapper(const int x)
{
    return round(-0.0135663 * x * x + 2.17444 * x - 83.9346);
}

int main()
{
    int entries[4] = {0, 0, 0, 0};
    string line;
    {
        //  Reading line from file
        ifstream myfile("./rosalind_dna.txt");
        if (!myfile.is_open())
            return 1;
        getline (myfile,line);
        myfile.close();
    }
    for_each(line.begin(), line.end(), [&](const char c){ ++entries[mapper(c)];});
    for (int i = 0; i < 4; ++i)
        cout << entries[i] << " ";
    return 0;
}
