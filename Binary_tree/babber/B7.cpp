


// Left view of binary tree 

#include<bits/stdc++.h>
using namespace std;



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void recurrsion(TreeNode* root, int leval, vector<int> & ans){
            // leval yaha pass by refernce nahi pass karna hai 

            //base condition 
            if(root == NULL) return;

            // NRL

            if(ans.size()==leval){
                ans.push_back(root->val);
            }

            if(root->right != NULL ){
                recurrsion(root->right,leval+1,ans);
            }
            // yaha per else if nahi likhna hai
            if(root->left != NULL){
                recurrsion(root->left,leval+1,ans);
            }

    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        recurrsion(root,0,ans);
        return ans;
    }
};

int main(){

}