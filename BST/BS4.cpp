// Diameter of BST :- Fast way

// keep track of height on the way to finding the Diameter

// Definition for a binary tree node.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int D = 0;
    int maxDepth(TreeNode *root)
    {

        if (root == NULL)
        {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        int currD = left + right;

        D = max(currD, D);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {

        int t = maxDepth(root);

        return D;
    }
};