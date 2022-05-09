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

struct Node *buildTree(vector<int> &postorder, vector<int> &inorder, int start, int end)
{
    static int curr = postorder.size() - 1;

    if (start > end)
    {
        return NULL;
    }

    int pos = 0;
    while (inorder[pos] != postorder[curr])
    {
        pos++;
    }

    curr--;

    struct Node *root = new Node(inorder[pos]);
    root->right = buildTree(postorder, inorder, pos + 1, end);
    root->left = buildTree(postorder, inorder, start, pos - 1);
    return root;
}

int main()
{
    vector<int> postorder = {1, 2, 4, 3, 5};
    vector<int> inorder = {4, 2, 1, 5, 3};

    struct Node *root = buildTree(postorder, inorder, 0, inorder.size() - 1);

    inOrder(root);
    return 0;
}