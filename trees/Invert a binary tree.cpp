#include <iostream>
#include <queue>
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

void levelOrder(struct Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
            cout << endl;
        }
    }
}

Node *invertTree(Node *root)
{
    if (root == NULL)
        return root;

    invertTree(root->left);
    invertTree(root->right);

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    return root;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // printing levelorder
    cout << "printing levelorder before inverting" << endl;
    levelOrder(root);

    Node *newRoot = invertTree(root);

    // printing levelorder
    cout << "\nprinting levelorder after inverting" << endl;
    levelOrder(newRoot);

    return 0;
}