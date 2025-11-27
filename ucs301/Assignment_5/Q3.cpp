#include <iostream>

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int value)
{
    Node *node = new Node;
    node->data = value;
    node->next = nullptr;
    return node;
}

void appendNode(Node *&head, int value)
{
    Node *node = createNode(value);
    if (!head)
    {
        head = node;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = node;
}

Node *findMiddle(Node *head)
{
    if (!head)
    {
        return nullptr;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    int n;
    std::cout << "Enter number of nodes: ";
    std::cin >> n;
    Node *head = nullptr;
    std::cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        int value;
        std::cin >> value;
        appendNode(head, value);
    }
    Node *middle = findMiddle(head);
    if (middle)
    {
        std::cout << "Middle element: " << middle->data << '\n';
    }
    else
    {
        std::cout << "List is empty." << '\n';
    }
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
