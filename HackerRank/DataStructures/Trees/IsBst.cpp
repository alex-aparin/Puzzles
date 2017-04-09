/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/

   bool is_valid(Node* root, const int l, const int r)
   {
       if (root == 0)
           return true;
       const int d = root->data;
       return (l < d && d < r && is_valid(root->left, l, d) && is_valid(root->right, d, r));
   }
                   
   bool checkBST(Node* root) 
   {
       return is_valid(root, -1, 10000 + 1);
   }
