/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
    Node* const copy_head = head;
    Node* prev_node = 0;
    for (; position != 0; --position, head = head->next)
        prev_node = head;
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = head;
    if (prev_node == 0)
        return new_node;
    prev_node->next = new_node;
    return copy_head;
}
