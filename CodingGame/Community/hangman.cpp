#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HangmanSim
{
public:
    HangmanSim(const string& key) : 
        m_key(key), m_marks(key.size(), false), m_mistakes(0), m_rest_guesses(key.size() - count(key.begin(), key.end(), ' '))
    {
    }
    HangmanSim& execute(const string& attempts)
    {
        for (size_t i = 0; mistakes_allowed() && !guesses_ended() && i < attempts.size(); ++i)
        {
            if (attempts[i] == ' ')
                continue;
            const int init_rest_guesses = m_rest_guesses;
            for (size_t key_id = 0; key_id < m_key.size(); ++key_id)
            {
                if (m_marks[key_id])
                    continue;
                if (tolower(m_key[key_id]) == tolower(attempts[i]))
                {
                    m_marks[key_id] = true;
                    --m_rest_guesses;;
                }
            }
            if (init_rest_guesses == m_rest_guesses)
                ++m_mistakes;
        }
        return *this;
    }
    void draw(void)
    {
        vector<string> image = 
        {
            "+--+ ",
            "|    ",
            "|    ",
            "|\\   "
        };
        const vector<pair<int, char>> mistakes = 
            {
                {0, 'x'},
                {8, 'o'},
                {13, '|'},
                {12, '/'},
                {14, '\\'},
                {17, '/'},
                {19, '\\'},
            };
        for (int mist = m_mistakes; 0 < mist; --mist)
        {
            const int index = mistakes[mist].first;
            const char c = mistakes[mist].second;
            image[index / 5][index % 5] = c;
        }
        for_each(image.begin(), image.end(), 
            [](string& str)
            {
                while (str.back() == ' ')
                    str.pop_back();
                cout << str << endl;
            });
        for (size_t i = 0; i < m_key.size(); ++i)
        {
            if (m_marks[i] || m_key[i] == ' ')
                cout << m_key[i];
            else
                cout << '_';
        }
        cout << endl;
    }
private:
    bool mistakes_allowed()
    {
        return m_mistakes < 6;
    }
    bool guesses_ended()
    {
        return m_rest_guesses == 0;
    }
    const string m_key;
    vector<bool> m_marks;
    int m_mistakes;
    int m_rest_guesses;
};

int main()
{
    string word;
    getline(cin, word);
    string chars;
    getline(cin, chars);
    HangmanSim(word).execute(chars).draw();
}
