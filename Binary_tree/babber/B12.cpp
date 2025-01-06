
// Zig -Zag Level order traversal 

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

    void levalOrder(TreeNode * root,  vector<vector<int>> & ans){
        if(root == NULL) return;

        queue <TreeNode* > q;
        q.push(root);

        int t = 1;

        while(!q.empty()){
            int size = q.size();
            vector<int> temp;

            for(int i = 0 ; i < size; i++){
                TreeNode* front = q.front();
                q.pop();

                temp.push_back(front-> val);

                if(front->left != NULL){
                    q.push(front->left);
                }
                if(front ->right != NULL){
                    q.push(front->right);
                }    
            }
            if(t >= 1){
                ans.push_back(temp);
            }else{
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
            }
            t = t*(-1); 
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        levalOrder(root, ans);
        return ans;
    }
};