#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void preOrder(Node *node)
{
    if (!node)
    {
        return;
    }
    std::cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node *node)
{
    if (!node)
    {
        return;
    }
    inOrder(node->left);
    std::cout << node->data << " ";
    inOrder(node->right);
}

void postOrder(Node *node)
{
    if (!node)
    {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->data << " ";
}

int main()
{
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    Node *root = new Node{1, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};
    root->left->left = new Node{4, nullptr, nullptr};
    root->left->right = new Node{5, nullptr, nullptr};
    root->right->right = new Node{6, nullptr, nullptr};

    std::cout << "Pre-order traversal: ";
    preOrder(root);
    std::cout << '\n';
    std::cout << "In-order traversal: ";
    inOrder(root);
    std::cout << '\n';
    std::cout << "Post-order traversal: ";
    postOrder(root);
    std::cout << '\n';
}
