/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    bool next = head != 0;
    while (next)
    {
        swap(head->prev, head->next);
        next = head->prev != 0;
        if (next)
            head = head->prev;
    }
    return head;
}
