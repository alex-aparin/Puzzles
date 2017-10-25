#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct Node
{
	Node() :
		cost(0), subtree_sum(0), nds()
	{}

	size_t cost;
	size_t subtree_sum;
	set<Node*> nds;
};

size_t compute_sum(Node* node, const Node* const parent)
{
	node->subtree_sum = node->cost;
	for (auto neighbor : node->nds)
	{
		if (neighbor == parent)
			continue;
		node->subtree_sum += compute_sum(neighbor, node);
	}
	return node->subtree_sum;
}

int main()
{
	size_t n;
	cin >> n;
	vector<Node> nodes(n + 1);
	for (size_t i = 1; i <= n; ++i)
		cin >> nodes[i].cost;
	for (size_t i = 1; i <= n; ++i)
	{
		size_t n1; cin >> n1;
		size_t n2; cin >> n2;
		nodes[n1].nds.insert(&nodes[n2]);
		nodes[n2].nds.insert(&nodes[n1]);
	}
    ptrdiff_t min_sum = compute_sum(&nodes[1], 0);
    for (size_t i = 1; i <= n; ++i)
	{
        min_sum = min(min_sum, abs((ptrdiff_t)(nodes[1].subtree_sum - 2 * nodes[i].subtree_sum)));
	}
	cout << min_sum << endl;
	return 0;
}
