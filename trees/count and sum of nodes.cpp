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
int totalSum(Node *root)
{
    if (root == NULL)
        return 0;
    return totalSum(root->left) + totalSum(root->right) + root->data;
}

int totalNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return totalNodes(root->left) + totalNodes(root->right) + 1;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Total number of nodes: " << totalNodes(root);

    cout << endl;

    cout << "Total sum of all nodes: " << totalSum(root);

    return 0;
}