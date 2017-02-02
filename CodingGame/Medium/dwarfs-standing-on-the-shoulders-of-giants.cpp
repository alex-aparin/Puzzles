#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef std::vector<int> ids_type;
struct Node
{
    Node(){}
    void add_child(const int node_id)
    {
        childs_id.push_back(node_id);
    }
    void add_parent(const int parent_id)
    {
        parents_id.push_back(parent_id);
    }
    bool is_sink(void) const
    {
        return parents_id.empty();
    }
    ids_type parents_id;
    ids_type childs_id;
};

typedef std::vector<Node> nodes_type;
typedef std::vector<int> sinks_type;

int compute_maximal_path_length(const nodes_type& graph, const int start_node_id) 
{
    int maximal_path_length = 0;
    for (int i = 0; i < graph[start_node_id].childs_id.size(); ++i)
    {
        const int current_maximal_path_length = compute_maximal_path_length(graph, graph[start_node_id].childs_id[i]);
        if (maximal_path_length < current_maximal_path_length)
            maximal_path_length = current_maximal_path_length;
    }
    return 1 + maximal_path_length;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n; // the number of relationships of influence
    cin >> n; cin.ignore();
    nodes_type graph(3 * n, Node());
    sinks_type sinks;
    for (int i = 0; i < n; i++) {
        int x; // a relationship of influence between two people (x influences y)
        int y;
        cin >> x >> y; cin.ignore();
        graph[x-1].add_child(y-1);
        graph[y-1].add_parent(x-1);
    }
    for (int i = 0; i < graph.size(); ++i)
        if (graph[i].is_sink())
            sinks.push_back(i);
    int maximal_path_length = 0;
    for (int i = 0; i < sinks.size(); ++i)
    {
        const int current_maximal_path_length = compute_maximal_path_length(graph, sinks[i]);
        if (maximal_path_length < current_maximal_path_length)
            maximal_path_length = current_maximal_path_length;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << maximal_path_length << endl; // The number of people involved in the longest succession of influences
}
