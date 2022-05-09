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
int maxHeight(Node *root)
{
    if (root == NULL)
        return 0;
    return max(maxHeight(root->left), maxHeight(root->right)) + 1;
}

// for each node calling maxHeight function
// hence increasing complexity O(n^2)
int diameter(Node *root)
{
    if (root == NULL)
        return 0;
    int currDiameter = maxHeight(root->left) + maxHeight(root->right) + 1;
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    return max(currDiameter, max(leftDiameter, rightDiameter));
}

// O(n) approach for finding diameter
// here we'll be carrying one extra pointer so that we don't
// have to call everytime one extra function

int calcDiameter(Node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDiameter = calcDiameter(root->left, &lh);
    int rDiameter = calcDiameter(root->right, &rh);
    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;
    return max(currDiameter, max(lDiameter, rDiameter));
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Height of binary tree: " << maxHeight(root);
    cout << "\nDiameter of binary tree: " << diameter(root);
    int height = 0;
    cout << "\nDiameter of binary tree: " << calcDiameter(root, &height);

    return 0;
}