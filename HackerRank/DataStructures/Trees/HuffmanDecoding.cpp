/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/

void decode_sym(node* root, size_t& pos, const string& s)
{
    if (root->left && s[pos] == '0')
    {
        ++pos;
        decode_sym(root->left, pos, s);
        return;
    }
    if (root->right && s[pos] == '1')
    {
        ++pos;
        decode_sym(root->right, pos, s);
        return;
    }
    cout << root->data;
}

void decode_huff(node* root, const string& s)
{
    size_t pos = 0;
    while (pos < s.size())    
        decode_sym(root, pos, s);
}
