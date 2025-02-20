
// Top view of Binary tree

// check Dry run inside the Note book

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {

        vector<int> ans;

        if (root == NULL)
            return ans;
        // Your code here

        map<int, int> mp;

        quque<pair<Node *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {

            auto top = q.front();
            q.pop();

            Node *front = top.first;
            int h = top.second;

            if (mp.find(h) == mp.end())
            {
                mp[h] = root->val;
            }

            // push left node into queue
            if (root->left != NULL)
                q.push({root->left, h - 1});

            // push right node into queue
            if (root->right != NULL)
                q.push({root->right, h + 1});
        }

        for (auto it : mp)
        {
            ans.push_back(it);
        }

        return ans;
    }
};
