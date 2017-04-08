/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/

node * insert(node * root, int value)
{
   if (root == 0)
   {
       node* temp = new node();
       temp->data = value;
       return temp;
   }
   if (value <= root->data)
       root->left = insert(root->left, value);
   else
       root->right = insert(root->right, value);
   return root;
}
