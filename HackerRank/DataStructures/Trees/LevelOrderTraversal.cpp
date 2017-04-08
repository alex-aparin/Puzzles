/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

//  I should not use standard list container in this exercise
struct ListNode
{
    ListNode(node* _data, ListNode* _next = 0) : 
        data(_data), next(_next)
    {        
    }
    ~ListNode()
    {
    }
    node* data;
    ListNode* next;
};

bool empty(ListNode* node)
{
    return node == 0;
}

node* pop_front(ListNode*& head)
{
    node* d = head->data;
    ListNode* temp = head;
    head = head->next;
    delete temp;
    return d;
}

void push_back(ListNode*& head, node* data)
{
    if (head == 0)
    {
        head = new ListNode(data);
        return;
    }
    ListNode* next = head;
    while (next->next != 0)
        next = next->next;
    next->next = new ListNode(data);
}

void LevelOrder(node * root)
{
    ListNode* childs_list = new ListNode(root);
    while (!empty(childs_list))
    {
        node* const n = pop_front(childs_list);
        cout << n->data << " ";
        if (n->left)
            push_back(childs_list, n->left);
        if (n->right)
            push_back(childs_list, n->right);
    }
}
