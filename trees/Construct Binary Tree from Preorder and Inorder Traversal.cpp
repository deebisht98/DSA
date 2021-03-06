#include <iostream>
#include <vector>
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

struct Node *buildTree(vector<int> &preorder, vector<int> &inorder, int start, int end)
{
    static int curr = 0;

    if (start > end)
    {
        return NULL;
    }

    int pos = 0;
    while (inorder[pos] != preorder[curr])
    {
        pos++;
    }

    curr++;

    struct Node *root = new Node(inorder[pos]);
    root->left = buildTree(preorder, inorder, start, pos - 1);
    root->right = buildTree(preorder, inorder, pos + 1, end);
    return root;
}

int main()
{
    vector<int> preorder = {1, 2, 4, 3, 5};
    vector<int> inorder = {4, 2, 1, 5, 3};

    struct Node *root = buildTree(preorder, inorder, 0, inorder.size() - 1);

    inOrder(root);
    return 0;
}