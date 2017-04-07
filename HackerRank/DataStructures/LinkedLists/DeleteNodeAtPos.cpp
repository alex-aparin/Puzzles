/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
    Node* const copy_head = head;
    Node* prev_node = 0;
    for (; position != 0; --position, head = head->next)
        prev_node = head;
    if (prev_node == 0)
    {    
        prev_node = head;
        head = head->next;
        delete prev_node;
        return head;
    }
    prev_node->next = head->next;
    delete head;
    return copy_head;
}
