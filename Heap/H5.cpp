// is binary tree is valid CBT or NOT 



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool levalOrderTraversal(TreeNode* root){
        if(root == NULL ) return true;
        queue<TreeNode *> q;
        q.push(root);
        bool isNull = false;
        
        while(!q.empty()){
            TreeNode* t = q.front();

            q.pop();

            if(t ==NULL){
                isNull = true;
            }else{
                if(isNull){
                return false;
                }

                q.push(t->left);
                q.push(t->right);

            }
        }
        return true;
    }  
    



    bool isCompleteTree(TreeNode* root) {
       return levalOrderTraversal(root);
    }
};