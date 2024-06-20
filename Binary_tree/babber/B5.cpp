

// balanced Binary tree

/*

 Its left subtree is height-balanced.
 Its right subtree is height-balanced.
The difference between heights of left & right subtree is not greater than 1
The difference between heights of left & right subtree is not greater than 1

*/

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int heightofTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = heightofTree(root->left);
        int right = heightofTree(root->right);

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;
        if (root->left == NULL && root->right == NULL)
            return true;

        bool curr = true;
        int val = abs(heightofTree(root->left) - heightofTree(root->right));

        if (val > 1)
            curr = false;

        return curr && isBalanced(root->left) && isBalanced(root->right);
    }
};

int main()
{
}