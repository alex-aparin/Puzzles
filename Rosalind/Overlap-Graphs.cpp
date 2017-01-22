#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

class Node
{
public:
     Node(const string& id, const string& content) :
         m_id(id.begin() + 1, id.end()), m_cnt(content)
     {
     }
     const string& id(void) const
     {
         return m_id;
     }
     bool less(const Node& rhs) const
     {
         const size_t lhs_size = m_cnt.size();
         for (size_t i = 0; i < 3; ++i)
             if (m_cnt[lhs_size - 3 + i] != rhs.m_cnt[i])
                return m_cnt[lhs_size - 3 + i] < rhs.m_cnt[i];
         return false;
     }
     bool great(const Node& rhs) const
     {
         const size_t lhs_size = m_cnt.size();
         for (size_t i = 0; i < 3; ++i)
             if (m_cnt[lhs_size - 3 + i] != rhs.m_cnt[i])
                return m_cnt[lhs_size - 3 + i] > rhs.m_cnt[i];
         return false;
     }
private:
    const string m_id;
    const string m_cnt;
};

int main()
{
    vector<Node> nodes;
    {
        ifstream myfile("./rosalind_grph.txt");
        if (!myfile.is_open())
            return 1;
        string temp;
        for (bool res = getline(myfile, temp); res;)
        {
            const string header = temp;
            string content;
            while ((res = getline(myfile, temp)) && temp[0] != '>')
                content += temp;
            nodes.push_back(Node(header, content));
        }
        myfile.close();
    }
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        for (size_t j = 0; j < nodes.size(); ++j)
        {
            if (i == j)
                continue;
            if (!nodes[i].less(nodes[j]) && !nodes[i].great(nodes[j]))
                cout << nodes[i].id() << " " << nodes[j].id() << endl;
        }
    }
    return 0;
}
