#include <iostream>

struct Node
{
    char data;
    Node *prev;
    Node *next;
};

Node *createNode(char value)
{
    Node *node = new Node;
    node->data = value;
    node->prev = nullptr;
    node->next = nullptr;
    return node;
}

void appendNode(Node *&head, Node *&tail, char value)
{
    Node *node = createNode(value);
    if (!head)
    {
        head = node;
        tail = node;
        return;
    }
    tail->next = node;
    node->prev = tail;
    tail = node;
}

bool isPalindrome(Node *head, Node *tail)
{
    while (head && tail && head != tail && tail->next != head)
    {
        if (head->data != tail->data)
        {
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

void freeList(Node *&head)
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    int n;
    std::cout << "Enter number of nodes: ";
    std::cin >> n;
    Node *head = nullptr;
    Node *tail = nullptr;
    std::cout << "Enter characters: ";
    for (int i = 0; i < n; i++)
    {
        char value;
        std::cin >> value;
        appendNode(head, tail, value);
    }
    if (isPalindrome(head, tail))
    {
        std::cout << "Palindrome" << '\n';
    }
    else
    {
        std::cout << "Not Palindrome" << '\n';
    }
    freeList(head);
    return 0;
}
