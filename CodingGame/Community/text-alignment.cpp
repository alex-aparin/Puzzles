#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void align_left(vector<string>& text, const size_t long_str_size)
{
    //  do nothing
}

void align_center(vector<string>& text, const size_t long_str_size)
{
    for (int i = 0; i < text.size(); ++i)
        text[i] = string((long_str_size - text[i].size()) / 2, ' ') + text[i];    
}

void align_right(vector<string>& text, const size_t long_str_size)
{
    for (int i = 0; i < text.size(); ++i)
        text[i] = string(long_str_size - text[i].size(), ' ') + text[i];
}

void align_justify(vector<string>& text, const size_t long_str_size)
{
    for (int i = 0; i < text.size(); ++i)
        if (text[i].size() != long_str_size)
        {
            const int padd_size = long_str_size - text[i].size();
            const int spaces_count = count(text[i].begin(), text[i].end(), ' ');
            const int larg_spaces = ceil(1.0 * padd_size / spaces_count);
            const int init_space = spaces_count * larg_spaces - padd_size;
            string new_str;
            new_str.reserve(long_str_size);
            bool first_intent = init_space != 0;
            for (int j = 0; j < text[i].size(); ++j)
            {
                new_str.push_back(text[i][j]);
                if (text[i][j] != ' ')
                    continue;
                const int cc = first_intent ? init_space : larg_spaces;
                first_intent = false;
                for (int k = 0; k < cc; ++k)
                    new_str.push_back(' ');
            }
            text[i] = new_str;
        }
}

int main()
{
    string alignment;
    getline(cin, alignment);
    int N;
    cin >> N; cin.ignore();
    size_t long_str_size = 0;
    vector<string> text(N, string());
    for (int i = 0; i < N; i++) 
    {
        getline(cin, text[i]);
        long_str_size = max(long_str_size, text[i].size());
    }
    if (alignment == "LEFT")
        align_left(text, long_str_size);
    else if (alignment == "RIGHT")
        align_right(text, long_str_size);
    else if (alignment == "CENTER")
        align_center(text, long_str_size);
    else if (alignment == "JUSTIFY")
        align_justify(text, long_str_size);        

    for (int i = 0; i < N; ++i)
        cout << text[i] << endl;
}
