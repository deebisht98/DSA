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

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
            return i;
    }
    return -1;
}

struct Node *buildTree(int preorder[], int inorder[], int start, int end)
{
    if (start > end)
        return NULL;

    static int index = 0;
    int curr = preorder[index];
    struct Node *root = new Node(curr);
    index++;
    if (start == end)
        return root;
    int pos = search(inorder, start, end, curr);
    root->left = buildTree(preorder, inorder, start, pos - 1);
    root->right = buildTree(preorder, inorder, pos + 1, end);
    return root;
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    struct Node *root = buildTree(preorder, inorder, 0, 4);

    inOrder(root);
    return 0;
}