#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Function to check whether a binary tree is balanced or not.
    int height(Node *root)
    {

        if (root == NULL)
        {
            return 0;
        }

        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh, rh) + 1;
    }
    bool isBalanced(Node *root)
    {
        if (root == NULL)
            return true;

        if (!isBalanced(root->left))
            return false;
        if (!isBalanced(root->right))
            return false;

        int lh = height(root->left);
        int rh = height(root->right);

        if (abs(lh - rh) <= 1)
            return true;
        else
            return false;
    }
    bool isBalancedFast(Node *root, int *height)
    {

        if (root == NULL)
        {
            return true;
        }
        int lh = 0, rh = 0;
        if (isBalancedFast(root->left, &lh) == false)
        {
            return false;
        }
        if (isBalancedFast(root->right, &rh) == false)
        {
            return false;
        }
        *height = max(lh, rh) + 1;
        if (abs(lh - rh) <= 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
