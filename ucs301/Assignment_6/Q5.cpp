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

bool isCircular(Node *head)
{
    if (!head)
    {
        return false;
    }
    Node *curr = head->next;
    while (curr && curr != head)
    {
        curr = curr->next;
    }
    return curr == head;
}

void freeList(Node *&head)
{
    Node *curr = head;
    while (curr)
    {
        Node *temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
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
    char makeCircular;
    std::cout << "Make list circular? (y/n): ";
    std::cin >> makeCircular;
    if (makeCircular == 'y')
    {
        if (head)
        {
            Node *tail = head;
            while (tail->next)
            {
                tail = tail->next;
            }
            tail->next = head;
        }
    }
    if (isCircular(head))
    {
        std::cout << "Circular Linked List" << '\n';
    }
    else
    {
        std::cout << "Not a Circular Linked List" << '\n';
    }
    if (isCircular(head))
    {
        Node *curr = head->next;
        while (curr != head)
        {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete head;
    }
    else
    {
        freeList(head);
    }
    return 0;
}
