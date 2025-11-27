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

int countKey(Node *head, int key)
{
    int count = 0;
    while (head)
    {
        if (head->data == key)
        {
            count++;
        }
        head = head->next;
    }
    return count;
}

void deleteOccurrences(Node *&head, int key)
{
    while (head && head->data == key)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    Node *curr = head;
    Node *prev = nullptr;
    while (curr)
    {
        if (curr->data == key)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}

void displayList(Node *head)
{
    if (!head)
    {
        std::cout << '\n';
        return;
    }
    while (head)
    {
        std::cout << head->data;
        if (head->next)
        {
            std::cout << "->";
        }
        head = head->next;
    }
    std::cout << '\n';
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
    int key;
    std::cout << "Enter key: ";
    std::cin >> key;
    int count = countKey(head, key);
    std::cout << "Count: " << count << '\n';
    deleteOccurrences(head, key);
    std::cout << "Updated Linked List: ";
    displayList(head);
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
