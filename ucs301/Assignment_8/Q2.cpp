#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *searchRecursive(Node *root, int key)
{
    if (!root)
    {
        return nullptr;
    }
    if (root->data == key)
    {
        return root;
    }
    if (key < root->data)
    {
        return searchRecursive(root->left, key);
    }
    return searchRecursive(root->right, key);
}

Node *searchIterative(Node *root, int key)
{
    while (root)
    {
        if (root->data == key)
        {
            return root;
        }
        if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return nullptr;
}

Node *findMinimum(Node *root)
{
    if (!root)
    {
        return nullptr;
    }
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

Node *findMaximum(Node *root)
{
    if (!root)
    {
        return nullptr;
    }
    while (root->right)
    {
        root = root->right;
    }
    return root;
}

Node *inOrderSuccessor(Node *root, Node *node)
{
    if (!root || !node)
    {
        return nullptr;
    }
    if (node->right)
    {
        return findMinimum(node->right);
    }
    Node *successor = nullptr;
    Node *ancestor = root;
    while (ancestor)
    {
        if (node->data < ancestor->data)
        {
            successor = ancestor;
            ancestor = ancestor->left;
        }
        else if (node->data > ancestor->data)
        {
            ancestor = ancestor->right;
        }
        else
        {
            break;
        }
    }
    return successor;
}

Node *inOrderPredecessor(Node *root, Node *node)
{
    if (!root || !node)
    {
        return nullptr;
    }
    if (node->left)
    {
        return findMaximum(node->left);
    }
    Node *predecessor = nullptr;
    Node *ancestor = root;
    while (ancestor)
    {
        if (node->data > ancestor->data)
        {
            predecessor = ancestor;
            ancestor = ancestor->right;
        }
        else if (node->data < ancestor->data)
        {
            ancestor = ancestor->left;
        }
        else
        {
            break;
        }
    }
    return predecessor;
}

void printNodeValue(const char *label, Node *node)
{
    std::cout << label;
    if (node)
    {
        std::cout << node->data << '\n';
    }
}

int main()
{
    //          8
    //        /   \
    //       4     12
    //      / \   /  \
    //     2   6 10  14
    Node *root = new Node{8, nullptr, nullptr};
    root->left = new Node{4, nullptr, nullptr};
    root->right = new Node{12, nullptr, nullptr};
    root->left->left = new Node{2, nullptr, nullptr};
    root->left->right = new Node{6, nullptr, nullptr};
    root->right->left = new Node{10, nullptr, nullptr};
    root->right->right = new Node{14, nullptr, nullptr};

    printNodeValue("Minimum element: ", findMinimum(root));
    printNodeValue("Maximum element: ", findMaximum(root));

    int key;
    std::cout << "Enter value to search in BST: ";
    std::cin >> key;

    Node *recursiveResult = searchRecursive(root, key);
    if (recursiveResult)
    {
        std::cout << "Recursive search: found " << recursiveResult->data << '\n';
    }
    else
    {
        std::cout << "Recursive search: value not found\n";
    }

    Node *iterativeResult = searchIterative(root, key);
    if (iterativeResult)
    {
        std::cout << "Iterative search: found " << iterativeResult->data << '\n';
    }
    else
    {
        std::cout << "Iterative search: value not found\n";
    }

    if (recursiveResult)
    {
        printNodeValue("In-order successor: ", inOrderSuccessor(root, recursiveResult));
        printNodeValue("In-order predecessor: ", inOrderPredecessor(root, recursiveResult));
    }

    return 0;
}
