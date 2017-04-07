/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
    int size = 0;
    Node* temp = head;
    for (; temp != 0; ++size, temp = temp->next)
        ;
    size -= positionFromTail;
    for (--size, temp = head; size != 0; --size, temp = temp->next)
        ;
    return temp->data;
}
