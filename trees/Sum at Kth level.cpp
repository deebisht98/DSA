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

int kthLevelSum(struct Node *root, int k)
{
    if (root == NULL)
        return -1;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int sum = 0;
    int level = 0;

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            if (level == k)
                sum += node->data;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // printing levelorder
    cout << "printing sum at 2nd level" << endl;
    cout << kthLevelSum(root, 2);

    return 0;
}