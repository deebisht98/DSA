#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            ans.push_back(node->data);

            if (node->right)
            {
                q.push(node->right);
            }
            if (node->left)
            {
                q.push(node->left);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    // printing reverse levelorder
    cout << "printing reverse levelorder" << endl;
    vector<int> ans = reverseLevelOrder(root);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}