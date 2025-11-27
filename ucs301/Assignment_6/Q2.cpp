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
    node->next = node;
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
    Node *tail = head;
    while (tail->next != head)
    {
        tail = tail->next;
    }
    tail->next = node;
    node->next = head;
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
    if (!head)
    {
        std::cout << '\n';
        return 0;
    }
    Node *curr = head;
    do
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    std::cout << head->data << '\n';
    Node *start = head->next;
    while (start != head)
    {
        Node *temp = start;
        start = start->next;
        delete temp;
    }
    delete head;
    return 0;
}
