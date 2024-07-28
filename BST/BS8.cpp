
// 2 sum problem in BST


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
class Solution {
public:

    void inorderTraversal(TreeNode* root, vector<int>& ans){
        if(root== NULL) return;

        inorderTraversal(root->left,ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorderTraversal(root,ans);

        int start =0 ; 
        int end = ans.size()-1;


        while(start<end){
            if(ans[start]+ ans[end] == k){
                return true;
                break;
            }else if(ans[start]+ ans[end] < k){
                start++;
            }else{
                end--;
            }
        }

        return false;
    }
};