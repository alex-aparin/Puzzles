/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
    if (head == 0)
        return 0;
    Node* rev_head = head;
    head = head->next;
    rev_head->next = 0;
    while(head != 0)
    {
        Node* temp = head;
        head = head->next;
        temp->next = rev_head;
        rev_head = temp;
    }
    return rev_head;
}
