/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
    if (head == 0)
        return 0;
    Node* prev = head;
    for (Node* loc = prev->next; loc != 0;)
    {
        if (prev->data == loc->data)
        {
            loc = loc->next;
            delete prev->next;
            prev->next = loc;
            continue;
        }
        prev = loc;
        loc = loc->next;
    }
    return head;
}
