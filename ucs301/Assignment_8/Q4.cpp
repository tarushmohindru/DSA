#include <iostream>
#include <limits>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool isBSTUtil(Node *node, long long minValue, long long maxValue)
{
    if (!node)
    {
        return true;
    }
    if (node->data <= minValue || node->data >= maxValue)
    {
        return false;
    }
    return isBSTUtil(node->left, minValue, node->data) &&
           isBSTUtil(node->right, node->data, maxValue);
}

bool isBinarySearchTree(Node *root)
{
    return isBSTUtil(root, std::numeric_limits<long long>::min(),
                     std::numeric_limits<long long>::max());
}

void describeTree(const char *label, Node *root)
{
    std::cout << label;
    if (isBinarySearchTree(root))
    {
        std::cout << "This tree is a BST." << '\n';
    }
    else
    {
        std::cout << "This tree is NOT a BST." << '\n';
    }
}

int main()
{
    // Example BST
    Node *bstRoot = new Node{8, nullptr, nullptr};
    bstRoot->left = new Node{4, nullptr, nullptr};
    bstRoot->right = new Node{12, nullptr, nullptr};
    bstRoot->left->left = new Node{2, nullptr, nullptr};
    bstRoot->left->right = new Node{6, nullptr, nullptr};
    bstRoot->right->left = new Node{10, nullptr, nullptr};
    bstRoot->right->right = new Node{14, nullptr, nullptr};

    describeTree("First tree: ", bstRoot);

    Node *wrongRoot = new Node{8, nullptr, nullptr};
    wrongRoot->left = new Node{4, nullptr, nullptr};
    wrongRoot->right = new Node{12, nullptr, nullptr};
    wrongRoot->left->left = new Node{2, nullptr, nullptr};
    wrongRoot->left->right = new Node{9, nullptr, nullptr};
    wrongRoot->right->right = new Node{14, nullptr, nullptr};

    describeTree("Second tree: ", wrongRoot);

    return 0;
}
