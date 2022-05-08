#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inOrder(struct Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void preOrder(struct Node *root)
{
    if (root == NULL)
        return;
    preOrder(root->left);
    cout << root->data << " ";
    preOrder(root->right);
}

void postOrder(struct Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    cout << root->data << " ";
    postOrder(root->right);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // printing inorder
    inOrder(root);

    // printing preorder
    preOrder(root);

    // printing postOrder
    postOrder(root);

    return 0;
}