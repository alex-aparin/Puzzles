/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void show_top(node* root, const bool left)
{
    if (root == 0)
        return;
    if (left)
    {
        show_top(root->left, left);
        cout << root->data << " ";
    }
    else
    {
        cout << root->data << " ";
        show_top(root->right, left);   
    }
}

void top_view(node * root)
{
    show_top(root->left, true);
    cout << root->data << " ";
    show_top(root->right, false);
}
