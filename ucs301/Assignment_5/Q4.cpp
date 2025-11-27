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

Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    while (curr)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void displayList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << "->";
        temp = temp->next;
    }
    std::cout << "NULL" << '\n';
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
    head = reverseList(head);
    std::cout << "Reversed List: ";
    displayList(head);
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
