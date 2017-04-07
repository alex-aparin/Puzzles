/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
    Node* last = new Node();
    last->data = data;
    last->next = 0;
    if (head == 0)
        return last;
    Node* const copy_head = head;
    for (; head->next != 0; head = head->next)
        ;
    head->next = last;
    return copy_head;
}
