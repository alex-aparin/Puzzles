#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

int main()
{
    function<bool(const char)> predicate = [](const char c){return c == 'C' || c == 'G';};
    pair<string, double> max_gc_str("", 0.0);
    {
        ifstream myfile("./rosalind_gc.txt");
        if (!myfile.is_open())
            return 1;
        string header;
        string content;
        int occurs = 0;
        size_t size = 0;
        bool next = true;
        while (next)
        {
            next = getline(myfile, content);
            if (!next || content[0] == '>')
            {
                if (!header.empty())
                {
                    const double gc_rate = 100.0 * occurs / size;
                    if (max_gc_str.second < gc_rate)
                    {
                        max_gc_str.first = header;
                        max_gc_str.second = gc_rate;
                    }
                }
                header = content;
                occurs = 0;
                size = 0;
                continue;
            }
            occurs += count_if(content.begin(), content.end(), predicate);
            size += content.size();
        }
        myfile.close();
    }
    max_gc_str.first.erase(max_gc_str.first.begin());
    cout << max_gc_str.first << endl;
    cout << max_gc_str.second << endl;
    return 0;
}
