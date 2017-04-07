/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    int sizea = 0;
    for (Node* temp = headA; temp != 0; temp = temp->next)
        ++sizea;
    int sizeb = 0;
    for (Node* temp = headB; temp != 0; temp = temp->next)
        ++sizeb;
    for (; sizea > sizeb; headA = headA->next)
        --sizea;
    for (; sizeb > sizea; headB = headB->next)
        --sizeb;
    while (headA != headB)
    {
        headA = headA->next;    
        headB = headB->next;
    }
    return headA->data;
}
