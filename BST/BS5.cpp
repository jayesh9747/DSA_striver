// validate the BST



#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
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
    bool solution(TreeNode *root, long long ll, long long rl)
    {

        // base condtion
        if (root == NULL)
            return true;

        // check for root

        int t = root->val;

        if (t < ll || t > rl)
        {
            return false;
        }

        // move left
        bool left = solution(root->left, ll, t);
        bool right = solution(root->right, t, rl);

        return left && right;
    }

    bool isValidBST(TreeNode *root)
    {

        long long LL = -2147483648;
        long long RL = 2147483647;

        bool ans = solution(root, INT_MIN, INT_MAX);

        return ans;
    }
};