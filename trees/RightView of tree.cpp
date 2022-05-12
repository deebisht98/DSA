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
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        if (root != NULL)
        {

            queue<Node *> q;
            q.push(root);

            while (!q.empty())
            {
                int n = q.size();

                for (int i = 1; i <= n; i++)
                {
                    Node *temp = q.front();
                    q.pop();
                    // last element in queue
                    if (i == n)
                    {
                        ans.push_back(temp->data);
                    }
                    if (temp->left)
                    {
                        q.push(temp->left);
                    }
                    if (temp->right)
                    {
                        q.push(temp->right);
                    }
                }
            }
        }
        return ans;
    }
};
