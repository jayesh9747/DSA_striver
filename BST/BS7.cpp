// convert BST into Balanced BST



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

    // jab ese part mai todne ka ayae tab indexs se khelte hai 
    TreeNode* createBalancedBST(vector<int> v,int s , int e ){

        // base case  

        if(s > e){
            return NULL;
        }

        int mid = (s+e) / 2;
        int val = v[mid];
        TreeNode* root = new TreeNode(val);

        root->left = createBalancedBST(v,s,mid-1);
        root->right = createBalancedBST(v,mid+1,e);

        return root;
    }


    void inorderTraversal(TreeNode* root, vector<int>& ans){
        if(root== NULL) return;

        inorderTraversal(root->left,ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }

    TreeNode* balanceBST(TreeNode* root) {

        vector<int> ans;
        inorderTraversal(root ,ans);

        return createBalancedBST(ans,0,ans.size()-1);
        
    }
};