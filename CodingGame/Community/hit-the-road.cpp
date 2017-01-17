#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Node
{    
public:
    Node() : 
        m_id(0), m_counter(0), m_is_junct(false), m_left_t(0), m_right_t(0)
    {
        m_edges = edges_type();
    }
    void set_id(const int id)
    {
        m_id = id;
    }
    void connect(const Node* const node, const int cost)
    {
        m_edges.push_back(make_pair(node, cost));
    }
    void set_time_period(const int left_t, const int right_t)
    {
        m_is_junct = true;
        m_left_t = left_t;
        m_right_t = right_t;
    }
private:
    friend class NodesTraverser;
    typedef list<pair<const Node*, int>> edges_type;
    edges_type m_edges;
    int m_id;
    bool m_is_junct;
    int m_left_t;
    int m_right_t;
    mutable int m_counter;
};

class NodesTraverser
{
public:
    NodesTraverser(const vector<Node>& nodes) :
        m_nodes(nodes), m_s(0), m_t(0)
    {
        m_max_junc_time = 0;
        for (int i = 0; i < nodes.size(); ++i)
        {
            if (nodes[i].m_is_junct)
                m_max_junc_time = max(m_max_junc_time, nodes[i].m_right_t);
        }
    }
    bool can_reach(const int s, const int t)
    {
        m_s = s;
        m_t = t;
        return propagate(&m_nodes[m_s], 0);
    }
private:
    bool propagate(const Node* const node, const int r)
    {
        if (node->m_counter > 0 && r > m_max_junc_time)
            return false;
        if (node->m_is_junct && (r < node->m_left_t || node->m_right_t < r))
            return false;
        if (node->m_id == m_t)
            return true;
        bool res = false;
        for (Node::edges_type::const_iterator loc = node->m_edges.cbegin(); !res && loc != node->m_edges.cend(); ++loc)
        {
            loc->first->m_counter += 1;
            res = propagate(loc->first, r + loc->second);
            loc->first->m_counter -= 1;
        }
        return res;
        
    }
    int m_s;
    int m_t;
    const vector<Node>& m_nodes;
    int m_max_junc_time;
};

int main()
{
    int n;
    int m;
    int ntw;
    cin >> n >> m >> ntw; cin.ignore();
    int s;
    int t;
    cin >> s >> t; cin.ignore();
    vector<Node> nodes(n + m, Node());
    for (int i = 0; i < n; ++i)
        nodes[i].set_id(i);
    for (int i = 0; i < ntw; i++) {
        int v;
        int b;
        int e;
        cin >> v >> b >> e; cin.ignore();
        nodes[v].set_time_period(b, e);
    }
    for (int i = 0; i < m; i++) 
    {
        int u;
        int v;
        int d;
        cin >> u >> v >> d; cin.ignore();
        nodes[u].connect(&nodes[v], d);
    }
    const string res = NodesTraverser(nodes).can_reach(s, t) ? "true" : "false";
    cout << res << endl;
}
