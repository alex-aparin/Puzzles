/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    Node* new_node = new Node();
    {
        new_node->data = data;
        new_node->prev = 0;
        new_node->next = 0;
    }
    if (head == 0)
        return new_node;
    Node* prev = 0;
    Node* loc = head;
    while (loc != 0 && data >= loc->data)
    {
        prev = loc;
        loc = loc->next;
    }
    if (prev == 0)
    {
        new_node->next = loc;
        loc->prev = new_node;
        return new_node;
    }
    prev->next = new_node;
    new_node->prev = prev;
    new_node->next = loc;
    if (loc != 0)
        loc->prev = new_node;
    return head;
}
