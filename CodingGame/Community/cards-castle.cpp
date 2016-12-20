#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_stable_castle(const vector<string>& cards, const size_t H)
{
    string hs(H, '\\');
    for (size_t j = 0; j < 2 * H; ++j)
    {
        char v = '.';
        for (size_t i = 0; i < H; ++i)
        {
            const char c = cards[i][j];
            const char h = hs[i];
            const bool vert = v == '.' || 
                              v == '\\' && c == '/' ||
                              v == '/'  && c == '\\';
            const bool bad_hort = h == '\\' && c == '\\' ||
                                  h == '/' && c == '/' || 
                                  h == '.' && c == '\\' ||
                                  h == '/' && c == '.';
            if (vert && !bad_hort)
            {
                v = c;
                hs[i] = c;
                continue;
            }
            return false;
        }
    }
    
    return true;
}

int main()
{
    int H;
    cin >> H; cin.ignore();
    vector<string> cards;
    cards.reserve(H);
    for (int i = 0; i < H; i++) 
    {
        string s;
        getline(cin, s);
        cards.push_back(s);
    }
    const string res = is_stable_castle(cards, H) ? "STABLE" : "UNSTABLE";
    cout << res << endl;
}