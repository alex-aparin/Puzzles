#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    Node(const int _left, const int _right)    :
        depth(0), left(_left), right(_right)
    {
    }
    int depth;
    int left;
    int right;
};

typedef vector<Node> graph_type;

void update_depths(graph_type& graph, const int i, const int init_depth)
{
    if (i == 0)
        return;
    Node& node = graph[i];
    node.depth = init_depth;
    update_depths(graph, node.left, init_depth + 1);
    update_depths(graph, node.right, init_depth + 1);
}

void show_inorder(const graph_type& graph, const int i)
{
    if (i == 0)    
        return;
    show_inorder(graph, graph[i].left);
    cout << i << " ";
    show_inorder(graph, graph[i].right);
}

void swap_k_nodes(graph_type& graph, const int i, const int k)
{
    if (i == 0)    
       return;
    if (graph[i].depth % k == 0)
        swap(graph[i].left, graph[i].right);
    swap_k_nodes(graph, graph[i].left, k);
    swap_k_nodes(graph, graph[i].right, k);
}

int main() 
{
    int N; cin >> N;
    graph_type graph(N + 1, Node(0, 0));
    for (int i = 1; i <= N; ++i)
    {
        int left; cin >> left;
        int right; cin >> right;
        graph[i] = Node(left == -1 ? 0 : left, right == -1 ? 0 : right);
    }
    update_depths(graph, 1, 1);
    int T; cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        int K; cin >> K;
        swap_k_nodes(graph, 1, K);
        show_inorder(graph, 1);
        cout << endl;
    }
    return 0;
}
