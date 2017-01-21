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
     const string& content(void) const
     {
         return m_cnt;
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
     static bool pref_comp(const Node& lhs, const Node& rhs)
     {
         for (size_t i = 0; i < 3; ++i)
             if (lhs.m_cnt[i] != rhs.m_cnt[i])
                return lhs.m_cnt[i] < rhs.m_cnt[i];
         return false;
     }
     static bool suff_comp(const Node& lhs, const Node& rhs)
     {
         const size_t lhs_size = lhs.m_cnt.size();
         const size_t rhs_size = rhs.m_cnt.size();
         for (size_t i = 3; 1 <= i; --i)
             if (lhs.m_cnt[lhs_size - i] != rhs.m_cnt[rhs_size - i])
                return lhs.m_cnt[lhs_size - i] < rhs.m_cnt[rhs_size - i];
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
    vector<size_t> suff_ids(nodes.size(), 0);
    vector<size_t> pref_ids(nodes.size(), 0);
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        suff_ids[i] = i;
        pref_ids[i] = i;
    }
    sort(suff_ids.begin(), suff_ids.end(),
         [&](const size_t l, const size_t r)
         {
             return Node::suff_comp(nodes[l], nodes[r]);
         });
    sort(pref_ids.begin(), pref_ids.end(),
         [&](const size_t l, const size_t r)
         {
             return Node::pref_comp(nodes[l], nodes[r]);
         });
    for (size_t suff_pos = 0, pref_pos = 0;
            suff_pos < suff_ids.size() && pref_pos < pref_ids.size();)
    {
        for (; suff_pos < suff_ids.size() &&
               nodes[suff_ids[suff_pos]].less(nodes[pref_ids[pref_pos]]); ++suff_pos)
        {
        }
        for (; suff_pos < suff_ids.size() && pref_pos < pref_ids.size() &&
               nodes[suff_ids[suff_pos]].great(nodes[pref_ids[pref_pos]]); ++pref_pos)
        {
        }
        for (; suff_pos < suff_ids.size() && pref_pos < pref_ids.size() &&
               !nodes[suff_ids[suff_pos]].less(nodes[pref_ids[pref_pos]]) &&
               !nodes[suff_ids[suff_pos]].great(nodes[pref_ids[pref_pos]]); ++pref_pos)
        {
            if (suff_ids[suff_pos] != pref_ids[pref_pos])
                cout << nodes[suff_ids[suff_pos]].id() << " " << nodes[pref_ids[pref_pos]].id() << endl;
        }
    }
    return 0;
}
