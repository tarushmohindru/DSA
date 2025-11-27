#include <algorithm>
#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *findMinNode(Node *node)
{
    while (node && node->left)
    {
        node = node->left;
    }
    return node;
}

Node *insertNode(Node *root, int value)
{
    if (!root)
    {
        return new Node{value, nullptr, nullptr};
    }
    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertNode(root->right, value);
    }
    else
    {
        std::cout << "Duplicate value not inserted." << '\n';
    }
    return root;
}

Node *deleteNode(Node *root, int value, bool &deleted)
{
    if (!root)
    {
        return nullptr;
    }
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value, deleted);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value, deleted);
    }
    else
    {
        deleted = true;
        if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *successor = findMinNode(root->right);
        root->data = successor->data;
        bool dummy = false;
        root->right = deleteNode(root->right, successor->data, dummy);
    }
    return root;
}

int maxDepth(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node *root)
{
    if (!root)
    {
        return 0;
    }
    if (!root->left)
    {
        return 1 + minDepth(root->right);
    }
    if (!root->right)
    {
        return 1 + minDepth(root->left);
    }
    return 1 + std::min(minDepth(root->left), minDepth(root->right));
}

void inOrder(Node *root)
{
    if (!root)
    {
        return;
    }
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    Node *root = nullptr;

    int choice = 0;
    do
    {
        std::cout << "\n--- BST Operations ---" << '\n';
        std::cout << "1. Insert element" << '\n';
        std::cout << "2. Delete element" << '\n';
        std::cout << "3. Maximum depth" << '\n';
        std::cout << "4. Minimum depth" << '\n';
        std::cout << "5. Display In-order" << '\n';
        std::cout << "6. Exit" << '\n';
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            root = insertNode(root, value);
            break;
        }
        case 2:
        {
            int value;
            std::cout << "Enter value to delete: ";
            std::cin >> value;
            bool deleted = false;
            root = deleteNode(root, value, deleted);
            if (deleted)
            {
                std::cout << value << " deleted from BST." << '\n';
            }
            else
            {
                std::cout << value << " not found in BST." << '\n';
            }
            break;
        }
        case 3:
            std::cout << "Maximum depth: " << maxDepth(root) << '\n';
            break;
        case 4:
            std::cout << "Minimum depth: " << minDepth(root) << '\n';
            break;
        case 5:
            std::cout << "BST (In-order): ";
            inOrder(root);
            std::cout << '\n';
            break;
        case 6:
            std::cout << "Exiting program." << '\n';
            break;
        default:
            std::cout << "Invalid choice. Try again." << '\n';
        }
    } while (choice != 6);

    return 0;
}
