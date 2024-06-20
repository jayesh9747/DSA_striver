// Lowest Common Ancestor of a Binary Tree

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        // base case Ham return hi p and q karwa de rahe hai uper
        // and jab dono mil jaye tab ham apna root return karwa denge
        if (root == NULL)
            return NULL;
        if (root == p)
            return p;
        if (root == q)
            return q;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // searching

        if (left == NULL && right == NULL)
            return NULL;
        else if (left != NULL && right == NULL)
            return left;
        else if (left == NULL && right != NULL)
            return right;
        else
            return root;
    }
};