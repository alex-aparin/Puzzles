
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) 
    {
        const int height_with_left  = root->left != 0 ? 1 + height(root->left) : 0;
        const int height_with_right  = root->right != 0 ? 1 + height(root->right) : 0;
        return max(height_with_left, height_with_right);
    }
