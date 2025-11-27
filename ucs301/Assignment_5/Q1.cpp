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

void insertAtBeginning(Node *&head, int value)
{
    Node *node = createNode(value);
    node->next = head;
    head = node;
    std::cout << value << " inserted at the beginning." << '\n';
}

void insertAtEnd(Node *&head, int value)
{
    Node *node = createNode(value);
    if (!head)
    {
        head = node;
        std::cout << value << " inserted at the end." << '\n';
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = node;
    std::cout << value << " inserted at the end." << '\n';
}

void insertRelative(Node *&head, int value, int target, char choice)
{
    if (!head)
    {
        std::cout << "List is empty." << '\n';
        return;
    }
    if (choice == 'b')
    {
        if (head->data == target)
        {
            insertAtBeginning(head, value);
            return;
        }
        Node *prev = nullptr;
        Node *curr = head;
        while (curr && curr->data != target)
        {
            prev = curr;
            curr = curr->next;
        }
        if (!curr)
        {
            std::cout << "Target not found." << '\n';
            return;
        }
        Node *node = createNode(value);
        prev->next = node;
        node->next = curr;
        std::cout << value << " inserted before " << target << "." << '\n';
    }
    else if (choice == 'a')
    {
        Node *curr = head;
        while (curr && curr->data != target)
        {
            curr = curr->next;
        }
        if (!curr)
        {
            std::cout << "Target not found." << '\n';
            return;
        }
        Node *node = createNode(value);
        node->next = curr->next;
        curr->next = node;
        std::cout << value << " inserted after " << target << "." << '\n';
    }
    else
    {
        std::cout << "Invalid option." << '\n';
    }
}

void deleteFromBeginning(Node *&head)
{
    if (!head)
    {
        std::cout << "List is empty." << '\n';
        return;
    }
    Node *temp = head;
    head = head->next;
    std::cout << temp->data << " deleted from the beginning." << '\n';
    delete temp;
}

void deleteFromEnd(Node *&head)
{
    if (!head)
    {
        std::cout << "List is empty." << '\n';
        return;
    }
    if (!head->next)
    {
        std::cout << head->data << " deleted from the end." << '\n';
        delete head;
        head = nullptr;
        return;
    }
    Node *prev = nullptr;
    Node *curr = head;
    while (curr->next)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = nullptr;
    std::cout << curr->data << " deleted from the end." << '\n';
    delete curr;
}

void deleteSpecific(Node *&head, int target)
{
    if (!head)
    {
        std::cout << "List is empty." << '\n';
        return;
    }
    if (head->data == target)
    {
        deleteFromBeginning(head);
        return;
    }
    Node *prev = head;
    Node *curr = head->next;
    while (curr && curr->data != target)
    {
        prev = curr;
        curr = curr->next;
    }
    if (!curr)
    {
        std::cout << "Node not found." << '\n';
        return;
    }
    prev->next = curr->next;
    std::cout << curr->data << " deleted from the list." << '\n';
    delete curr;
}

void searchNode(Node *head, int target)
{
    int position = 1;
    Node *temp = head;
    while (temp)
    {
        if (temp->data == target)
        {
            std::cout << "Node found at position " << position << "." << '\n';
            return;
        }
        temp = temp->next;
        position++;
    }
    std::cout << "Node not found." << '\n';
}

void displayList(Node *head)
{
    if (!head)
    {
        std::cout << "List is empty." << '\n';
        return;
    }
    std::cout << "List elements: ";
    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << '\n';
}

int main()
{
    Node *head = nullptr;
    int choice;
    do
    {
        std::cout << "\n--- Singly Linked List Menu ---" << '\n';
        std::cout << "1. Insert at beginning" << '\n';
        std::cout << "2. Insert at end" << '\n';
        std::cout << "3. Insert before/after node" << '\n';
        std::cout << "4. Delete from beginning" << '\n';
        std::cout << "5. Delete from end" << '\n';
        std::cout << "6. Delete specific node" << '\n';
        std::cout << "7. Search for node" << '\n';
        std::cout << "8. Display list" << '\n';
        std::cout << "9. Exit" << '\n';
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int value;
            std::cout << "Enter value: ";
            std::cin >> value;
            insertAtBeginning(head, value);
            break;
        }
        case 2:
        {
            int value;
            std::cout << "Enter value: ";
            std::cin >> value;
            insertAtEnd(head, value);
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
            insertRelative(head, value, target, option);
            break;
        }
        case 4:
            deleteFromBeginning(head);
            break;
        case 5:
            deleteFromEnd(head);
            break;
        case 6:
        {
            int target;
            std::cout << "Enter value to delete: ";
            std::cin >> target;
            deleteSpecific(head, target);
            break;
        }
        case 7:
        {
            int target;
            std::cout << "Enter value to search: ";
            std::cin >> target;
            searchNode(head, target);
            break;
        }
        case 8:
            displayList(head);
            break;
        case 9:
            std::cout << "Exiting program." << '\n';
            break;
        default:
            std::cout << "Invalid choice." << '\n';
        }
    } while (choice != 9);
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
