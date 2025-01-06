//  vertical order traversal 


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


    vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> nodes; 

    queue<pair<TreeNode*, pair<int, int>>> q; 

    if (root == NULL) return {};

    q.push({root, {0, 0}});  

    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        
        TreeNode* node = it.first;
        int vertical = it.second.first; 
        int level = it.second.second;  
        
        
        nodes[vertical][level].insert(node->val);

        if (node->left != NULL) {
            q.push({node->left, {vertical - 1, level + 1}});
        }
        if (node->right != NULL) {
            q.push({node->right, {vertical + 1, level + 1}});
        }
    }

    vector<vector<int>> ans;

   
    for (auto it : nodes) {
        vector<int> temp;
        for (auto lvl : it.second) {
            temp.insert(temp.end(), lvl.second.begin(), lvl.second.end());
        }
        ans.push_back(temp);
    }

    return ans;
}
};