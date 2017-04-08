/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/

node* next_ancestor(node* root, int v1, int v2)
{
    const int d = root->data;
    if (v1 < d && v2 < d)    
        return root->left;
    if (d < v1 && d < v2)    
        return root->right;
    return 0;
}

node* lca(node* root, int v1, int v2)
{
    for (node* next_anc = next_ancestor(root, v1, v2); next_anc != 0; )
    {
        root = next_anc; 
        next_anc = next_ancestor(root, v1, v2);
    }
    return root;
}
