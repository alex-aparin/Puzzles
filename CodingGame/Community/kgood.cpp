#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int long_k_str(const int k, const string& str)
{
    vector<int> matches(26, 0);
    int max_len = 0;
    size_t beg = 0;
    size_t end = 0;
    int temp_k = 0;
    for (; end < str.size(); ++end)
    {
        const int index = str[end] - 'a';
        if (matches[index]++ == 0 && temp_k++ == k)
        {
            matches[index] = 0;
            temp_k = k;
            break;
        }
    }
    max_len = end - beg;
    for (; end < str.size();)
    {
        while (--matches[str[beg++] - 'a'] != 0) ;
        --temp_k;
        for (; end < str.size(); ++end)
        {
            const int index = str[end] - 'a';
            if (matches[index]++ == 0 && temp_k++ == k)
            {
                matches[index] = 0;
                temp_k = k;
                break;
            }
        }
        if (temp_k == k)    
            max_len = end-beg >  max_len ? end-beg : max_len;
    }
    return max_len;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string S;
    getline(cin, S);
    int K;
    cin >> K; cin.ignore();

    cout << long_k_str(K, S) << endl;
}
