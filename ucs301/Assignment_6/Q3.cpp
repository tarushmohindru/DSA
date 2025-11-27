#include <iostream>

struct DNode
{
    int data;
    DNode *prev;
    DNode *next;
};

struct CNode
{
    int data;
    CNode *next;
};

DNode *createDNode(int value)
{
    DNode *node = new DNode;
    node->data = value;
    node->prev = nullptr;
    node->next = nullptr;
    return node;
}

CNode *createCNode(int value)
{
    CNode *node = new CNode;
    node->data = value;
    node->next = node;
    return node;
}

void appendDNode(DNode *&head, DNode *&tail, int value)
{
    DNode *node = createDNode(value);
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

void appendCNode(CNode *&head, int value)
{
    CNode *node = createCNode(value);
    if (!head)
    {
        head = node;
        return;
    }
    CNode *tail = head;
    while (tail->next != head)
    {
        tail = tail->next;
    }
    tail->next = node;
    node->next = head;
}

int sizeDoubly(DNode *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

int sizeCircular(CNode *head)
{
    if (!head)
    {
        return 0;
    }
    int count = 0;
    CNode *curr = head;
    do
    {
        count++;
        curr = curr->next;
    } while (curr != head);
    return count;
}

void freeDoubly(DNode *&head)
{
    while (head)
    {
        DNode *temp = head;
        head = head->next;
        delete temp;
    }
}

void freeCircular(CNode *&head)
{
    if (!head)
    {
        return;
    }
    CNode *curr = head->next;
    while (curr != head)
    {
        CNode *temp = curr;
        curr = curr->next;
        delete temp;
    }
    delete head;
    head = nullptr;
}

int main()
{
    int n;
    std::cout << "Enter number of nodes for doubly linked list: ";
    std::cin >> n;
    DNode *dHead = nullptr;
    DNode *dTail = nullptr;
    std::cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        int value;
        std::cin >> value;
        appendDNode(dHead, dTail, value);
    }
    std::cout << "Size of doubly linked list: " << sizeDoubly(dHead) << '\n';
    int m;
    std::cout << "Enter number of nodes for circular linked list: ";
    std::cin >> m;
    CNode *cHead = nullptr;
    std::cout << "Enter values: ";
    for (int i = 0; i < m; i++)
    {
        int value;
        std::cin >> value;
        appendCNode(cHead, value);
    }
    std::cout << "Size of circular linked list: " << sizeCircular(cHead) << '\n';
    freeDoubly(dHead);
    freeCircular(cHead);
    return 0;
}
