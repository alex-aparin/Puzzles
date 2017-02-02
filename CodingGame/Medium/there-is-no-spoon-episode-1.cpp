#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct Node
{
    Node(const int _x, const int _y) : x(_x), y(_y), right_node(0), bottom_node(0){}
    void add_to_right(Node* const node)
    {
        right_node = node;
    }
    void add_to_bottom(Node* const node)
    {
        bottom_node = node;
    }
    int x;
    int y;
    Node* right_node;
    Node* bottom_node;
};

typedef std::vector<Node*> p_nodes_type;
typedef std::vector<Node*> nodes_type;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    nodes_type nodes;
    p_nodes_type p_nodes(width);
    for (int i = 0; i < p_nodes.size(); ++i)
        p_nodes[i] = 0;
    Node* last_right_node;
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        last_right_node = 0;
        for (size_t j = 0; j < line.size(); ++j)
        if (line[j] == '0')
        {
            nodes.push_back(new Node(j, i));
            if (last_right_node)
                last_right_node->add_to_right(nodes.back());
            last_right_node = nodes.back();
            if (p_nodes[j])
                p_nodes[j]->add_to_bottom(nodes.back());
            p_nodes[j] = nodes.back();
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        cout << nodes[i]->x << " " << nodes[i]->y;
        if (nodes[i]->right_node != 0)
            cout << " " << nodes[i]->right_node->x << " " << nodes[i]->right_node->y;
        else
            cout << " " << -1 << " " << -1;
        if (nodes[i]->bottom_node != 0)
            cout << " " << nodes[i]->bottom_node->x << " " << nodes[i]->bottom_node->y;
        else
            cout << " " << -1 << " " << -1;
        cout << endl;
    }
}
