#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>

using namespace std;
typedef std::list<int> ints_type;

struct Node
{
    Node(const int _id = -1) : id(_id)
    {}
    bool is_leaf(void) const
    {
        return neighbors.size() == 1;
    }
    void add_node(const Node& node)
    {
        neighbors.push_back(node.id);
    }
    void remove_neighbor(const int node_id)
    {
        ints_type::iterator res_it = std::find(neighbors.begin(), neighbors.end(), node_id);
        if (res_it != neighbors.end())
            neighbors.erase(res_it);
    }
    int first_neighbor(void) const
    {
        return neighbors.front();
    }
    int id;
    ints_type neighbors;
};

void link_nodes(Node& lhs_node, Node& rhs_node)
{
    lhs_node.add_node(rhs_node);
    rhs_node.add_node(lhs_node);
}

typedef std::map<int, Node> nodes_type;

void splice_node(Node& node, nodes_type& nodes)
{
        
}

void print_leaves(const ints_type& leaves, bool init_leaves)
{
    if (init_leaves)
        cerr << "Init LEAVES" << endl;
    else
        cerr << "NEW LEAVES" << endl;
    for (ints_type::const_iterator loc = leaves.begin(); loc != leaves.end(); ++loc)
        cerr << *loc << endl;
}

void print_tree(const nodes_type& nodes)
{
    cerr << "TREE" << endl;
    for (auto loc = nodes.begin(); loc != nodes.end(); ++loc)
    {
        cerr << "ID VERTEX: " << loc->first << endl;
        cerr << "NEIGHBORS: ";
        for (auto loc2 = loc->second.neighbors.begin(); loc2 != loc->second.neighbors.end(); ++loc2)
            cerr << *loc2 << " , ";
        cerr << endl;
    }
}

int compute_propagation_levels(nodes_type& nodes)
{
    int level = 0;
    ints_type leaves;
    for (nodes_type::const_iterator loc = nodes.begin(); loc != nodes.end(); ++loc)
        if (loc->second.is_leaf())
            leaves.push_back(loc->first);
    while (leaves.size() >= 2)
    {
        ++level;
        cerr << "LEVEL: " << level << endl;
        ints_type new_leaves;
        if (level == 2)
        {
            print_leaves(new_leaves, true);
        }
        while (leaves.empty() == false)
        {
            const int first_neighbor_id = nodes.at(leaves.front()).first_neighbor();
            nodes[first_neighbor_id].remove_neighbor(leaves.front());
            nodes[leaves.front()].remove_neighbor(first_neighbor_id);
            if (level == 2)
                cerr << "LEVEL 2, LEAF: " << leaves.front() << endl;
            if (nodes.at(first_neighbor_id).is_leaf())
            {
                if (level == 2)
                cerr << "LEVEL 2: NEIGHBOR " << first_neighbor_id << endl;
                new_leaves.push_back(first_neighbor_id);
            }
            leaves.pop_front();    
        }
        if (level == 2)
        {
            print_leaves(leaves, true);
            print_leaves(new_leaves, true);
            cerr << "BUGAGAG" << endl;
        }
        leaves.splice(leaves.end(), new_leaves); 
    }
    return level;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    nodes_type nodes;
    int n; // the number of adjacency relations
    cin >> n; cin.ignore();
    cerr << "LIST OF RELATIONS" << endl;
    for (int i = 0; i < n; i++) {
        int xi; // the ID of a person which is adjacent to yi
        int yi; // the ID of a person which is adjacent to xi
        cin >> xi >> yi; cin.ignore();
        Node lhs_node(xi);
        std::pair<nodes_type::iterator, bool> lhs_node_it = 
        nodes.insert(nodes_type::value_type(xi, lhs_node));
        Node rhs_node(yi);
        std::pair<nodes_type::iterator, bool> rhs_node_it = 
        nodes.insert(nodes_type::value_type(yi, rhs_node));
        link_nodes(lhs_node_it.first->second, rhs_node_it.first->second);
        cerr << "(" << xi << "," << yi << ")" << endl;
    }
    cout << compute_propagation_levels(nodes) << endl; // The minimal amount of steps required to completely propagate the advertisement
}
