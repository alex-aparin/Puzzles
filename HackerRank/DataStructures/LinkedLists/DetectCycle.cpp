/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    const int list_size = 100;
    int curr_size = 0;
    for (; head != 0 && curr_size <= list_size; ++curr_size, head = head->next)
        ;
    return curr_size > list_size;
}
