#include <iostream>

struct CNode
{
    int data;
    CNode *next;
};

struct DNode
{
    int data;
    DNode *prev;
    DNode *next;
};

CNode *createCNode(int value)
{
    CNode *node = new CNode;
    node->data = value;
    node->next = node;
    return node;
}

DNode *createDNode(int value)
{
    DNode *node = new DNode;
    node->data = value;
    node->prev = nullptr;
    node->next = nullptr;
    return node;
}

void insertCircularBeginning(CNode *&head, int value)
{
    CNode *node = createCNode(value);
    if (!head)
    {
        head = node;
        std::cout << value << " inserted at beginning." << '\n';
        return;
    }
    CNode *tail = head;
    while (tail->next != head)
    {
        tail = tail->next;
    }
    node->next = head;
    tail->next = node;
    head = node;
    std::cout << value << " inserted at beginning." << '\n';
}

void insertCircularEnd(CNode *&head, int value)
{
    CNode *node = createCNode(value);
    if (!head)
    {
        head = node;
        std::cout << value << " inserted at end." << '\n';
        return;
    }
    CNode *tail = head;
    while (tail->next != head)
    {
        tail = tail->next;
    }
    tail->next = node;
    node->next = head;
    std::cout << value << " inserted at end." << '\n';
}

void insertCircularRelative(CNode *&head, int value, int target, char option)
{
    if (!head)
    {
        std::cout << "List is empty." << '\n';
        return;
    }
    CNode *curr = head;
    CNode *prev = nullptr;
    do
    {
        if (curr->data == target)
        {
            break;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
    if (curr->data != target)
    {
        std::cout << "Target not found." << '\n';
        return;
    }
    if (option == 'b')
    {
        if (curr == head)
        {
            insertCircularBeginning(head, value);
            return;
        }
        CNode *node = createCNode(value);
        node->next = curr;
        prev->next = node;
        std::cout << value << " inserted before " << target << "." << '\n';
    }
    else if (option == 'a')
    {
        CNode *node = createCNode(value);
        node->next = curr->next;
        curr->next = node;
        std::cout << value << " inserted after " << target << "." << '\n';
    }
    else
    {
        std::cout << "Invalid option." << '\n';
    }
}

void deleteCircularValue(CNode *&head, int value)
{
    if (!head)
    {
        std::cout << "List is empty." << '\n';
        return;
    }
    CNode *curr = head;
    CNode *prev = nullptr;
    do
    {
        if (curr->data == value)
        {
            break;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
    if (curr->data != value)
    {
        std::cout << "Node not found." << '\n';
        return;
    }
    if (curr == head && curr->next == head)
    {
        std::cout << curr->data << " deleted." << '\n';
        delete curr;
        head = nullptr;
        return;
    }
    if (curr == head)
    {
        CNode *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }
        head = head->next;
        tail->next = head;
        std::cout << curr->data << " deleted." << '\n';
        delete curr;
        return;
    }
    prev->next = curr->next;
    std::cout << curr->data << " deleted." << '\n';
    delete curr;
}

void searchCircular(CNode *head, int value)
{
    if (!head)
    {
        std::cout << "List is empty." << '\n';
        return;
    }
    int position = 1;
    CNode *curr = head;
    do
    {
        if (curr->data == value)
        {
            std::cout << "Node found at position " << position << "." << '\n';
            return;
        }
        curr = curr->next;
        position++;
    } while (curr != head);
    std::cout << "Node not found." << '\n';
}

void displayCircular(CNode *head)
{
    if (!head)
    {
        std::cout << "List is empty." << '\n';
        return;
    }
    std::cout << "Circular List: ";
    CNode *curr = head;
    do
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    std::cout << '\n';
}

void insertDoublyBeginning(DNode *&head, DNode *&tail, int value)
{
    DNode *node = createDNode(value);
    if (!head)
    {
        head = node;
        tail = node;
        std::cout << value << " inserted at beginning." << '\n';
        return;
    }
    node->next = head;
    head->prev = node;
    head = node;
    std::cout << value << " inserted at beginning." << '\n';
}

void insertDoublyEnd(DNode *&head, DNode *&tail, int value)
{
    DNode *node = createDNode(value);
    if (!tail)
    {
        head = node;
        tail = node;
        std::cout << value << " inserted at end." << '\n';
        return;
    }
    tail->next = node;
    node->prev = tail;
    tail = node;
    std::cout << value << " inserted at end." << '\n';
}

void insertDoublyRelative(DNode *&head, DNode *&tail, int value, int target, char option)
{
    if (!head)
    {
        std::cout << "List is empty." << '\n';
        return;
    }
    DNode *curr = head;
    while (curr && curr->data != target)
    {
        curr = curr->next;
    }
    if (!curr)
    {
        std::cout << "Target not found." << '\n';
        return;
    }
    if (option == 'b')
    {
        if (curr == head)
        {
            insertDoublyBeginning(head, tail, value);
            return;
        }
        DNode *node = createDNode(value);
        node->next = curr;
        node->prev = curr->prev;
        curr->prev->next = node;
        curr->prev = node;
        std::cout << value << " inserted before " << target << "." << '\n';
    }
    else if (option == 'a')
    {
        if (curr == tail)
        {
            insertDoublyEnd(head, tail, value);
            return;
        }
        DNode *node = createDNode(value);
        node->next = curr->next;
        node->prev = curr;
        curr->next->prev = node;
        curr->next = node;
        std::cout << value << " inserted after " << target << "." << '\n';
    }
    else
    {
        std::cout << "Invalid option." << '\n';
    }
}

void deleteDoublyValue(DNode *&head, DNode *&tail, int value)
{
    if (!head)
    {
        std::cout << "List is empty." << '\n';
        return;
    }
    DNode *curr = head;
    while (curr && curr->data != value)
    {
        curr = curr->next;
    }
    if (!curr)
    {
        std::cout << "Node not found." << '\n';
        return;
    }
    if (curr == head && curr == tail)
    {
        std::cout << curr->data << " deleted." << '\n';
        delete curr;
        head = nullptr;
        tail = nullptr;
        return;
    }
    if (curr == head)
    {
        head = head->next;
        head->prev = nullptr;
        std::cout << curr->data << " deleted." << '\n';
        delete curr;
        return;
    }
    if (curr == tail)
    {
        tail = tail->prev;
        tail->next = nullptr;
        std::cout << curr->data << " deleted." << '\n';
        delete curr;
        return;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    std::cout << curr->data << " deleted." << '\n';
    delete curr;
}

void searchDoubly(DNode *head, int value)
{
    if (!head)
    {
        std::cout << "List is empty." << '\n';
        return;
    }
    int position = 1;
    DNode *curr = head;
    while (curr)
    {
        if (curr->data == value)
        {
            std::cout << "Node found at position " << position << "." << '\n';
            return;
        }
        curr = curr->next;
        position++;
    }
    std::cout << "Node not found." << '\n';
}

void displayDoubly(DNode *head)
{
    if (!head)
    {
        std::cout << "List is empty." << '\n';
        return;
    }
    std::cout << "Doubly List: ";
    DNode *curr = head;
    while (curr)
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << '\n';
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

void freeDoubly(DNode *&head)
{
    while (head)
    {
        DNode *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    CNode *cHead = nullptr;
    DNode *dHead = nullptr;
    DNode *dTail = nullptr;
    int mainChoice;
    do
    {
        std::cout << "\n--- Main Menu ---" << '\n';
        std::cout << "1. Circular Linked List" << '\n';
        std::cout << "2. Doubly Linked List" << '\n';
        std::cout << "3. Exit" << '\n';
        std::cout << "Enter your choice: ";
        std::cin >> mainChoice;
        if (mainChoice == 1)
        {
            int choice;
            do
            {
                std::cout << "\n--- Circular List Menu ---" << '\n';
                std::cout << "1. Insert at beginning" << '\n';
                std::cout << "2. Insert at end" << '\n';
                std::cout << "3. Insert before/after node" << '\n';
                std::cout << "4. Delete node" << '\n';
                std::cout << "5. Search node" << '\n';
                std::cout << "6. Display list" << '\n';
                std::cout << "7. Back" << '\n';
                std::cout << "Enter your choice: ";
                std::cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    int value;
                    std::cout << "Enter value: ";
                    std::cin >> value;
                    insertCircularBeginning(cHead, value);
                    break;
                }
                case 2:
                {
                    int value;
                    std::cout << "Enter value: ";
                    std::cin >> value;
                    insertCircularEnd(cHead, value);
                    break;
                }
                case 3:
                {
                    int value;
                    int target;
                    char option;
                    std::cout << "Enter value: ";
                    std::cin >> value;
                    std::cout << "Enter target value: ";
                    std::cin >> target;
                    std::cout << "Insert before or after target? (b/a): ";
                    std::cin >> option;
                    insertCircularRelative(cHead, value, target, option);
                    break;
                }
                case 4:
                {
                    int value;
                    std::cout << "Enter value to delete: ";
                    std::cin >> value;
                    deleteCircularValue(cHead, value);
                    break;
                }
                case 5:
                {
                    int value;
                    std::cout << "Enter value to search: ";
                    std::cin >> value;
                    searchCircular(cHead, value);
                    break;
                }
                case 6:
                    displayCircular(cHead);
                    break;
                case 7:
                    break;
                default:
                    std::cout << "Invalid choice." << '\n';
                }
            } while (choice != 7);
        }
        else if (mainChoice == 2)
        {
            int choice;
            do
            {
                std::cout << "\n--- Doubly List Menu ---" << '\n';
                std::cout << "1. Insert at beginning" << '\n';
                std::cout << "2. Insert at end" << '\n';
                std::cout << "3. Insert before/after node" << '\n';
                std::cout << "4. Delete node" << '\n';
                std::cout << "5. Search node" << '\n';
                std::cout << "6. Display list" << '\n';
                std::cout << "7. Back" << '\n';
                std::cout << "Enter your choice: ";
                std::cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    int value;
                    std::cout << "Enter value: ";
                    std::cin >> value;
                    insertDoublyBeginning(dHead, dTail, value);
                    break;
                }
                case 2:
                {
                    int value;
                    std::cout << "Enter value: ";
                    std::cin >> value;
                    insertDoublyEnd(dHead, dTail, value);
                    break;
                }
                case 3:
                {
                    int value;
                    int target;
                    char option;
                    std::cout << "Enter value: ";
                    std::cin >> value;
                    std::cout << "Enter target value: ";
                    std::cin >> target;
                    std::cout << "Insert before or after target? (b/a): ";
                    std::cin >> option;
                    insertDoublyRelative(dHead, dTail, value, target, option);
                    break;
                }
                case 4:
                {
                    int value;
                    std::cout << "Enter value to delete: ";
                    std::cin >> value;
                    deleteDoublyValue(dHead, dTail, value);
                    break;
                }
                case 5:
                {
                    int value;
                    std::cout << "Enter value to search: ";
                    std::cin >> value;
                    searchDoubly(dHead, value);
                    break;
                }
                case 6:
                    displayDoubly(dHead);
                    break;
                case 7:
                    break;
                default:
                    std::cout << "Invalid choice." << '\n';
                }
            } while (choice != 7);
        }
        else if (mainChoice != 3)
        {
            std::cout << "Invalid choice." << '\n';
        }
    } while (mainChoice != 3);
    freeCircular(cHead);
    freeDoubly(dHead);
    return 0;
}
