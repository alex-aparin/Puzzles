/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
    if (headA == 0)
        return headB;
    if (headB == 0)
        return headA;
    Node* const new_head = headA->data <= headB->data ? headA : headB;
    Node* last_elem = new_head;
    while (headA != 0 && headB != 0)
    {
        Node* less_el = 0;
        if (headA->data <= headB->data)
        {
            less_el = headA;
            headA = headA->next;
        }
        else
        {
            less_el = headB;
            headB = headB->next;
        }
        last_elem->next = less_el;
        last_elem = less_el;
    }
    if (headA == 0)
        last_elem->next = headB;
    else
        last_elem->next = headA;
    return new_head;
}
