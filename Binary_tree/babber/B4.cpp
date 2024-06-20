// Diameter of binary tree

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
    int maxDepth(TreeNode *root)
    {

        if (root == NULL)
        {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {

        if (root == NULL)
            return 0;

        int maxleft = diameterOfBinaryTree(root->left);
        int maxright = diameterOfBinaryTree(root->right);

        int maxi = maxDepth(root->left) + maxDepth(root->right);

        return max(maxi, max(maxleft, maxright));
    }
};

int main()
{
}