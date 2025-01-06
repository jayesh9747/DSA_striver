// boundary traversal of binary tree



#include <vector>
using namespace std;

// Helper function to add the left boundary (excluding leaves)
void addLeftBoundary(TreeNode<int>* root, vector<int>& ans) {
    TreeNode<int>* curr = root->left;
    while (curr) {
        if (curr->left != NULL || curr->right != NULL) {
            ans.push_back(curr->data); 
        }
        if (curr->left) curr = curr->left; 
        else curr = curr->right;         
    }
}


// pre order traversal
void addLeaves(TreeNode<int>* root, vector<int>& ans) {
    if (!root) return;
    
    if (!root->left && !root->right) {
        ans.push_back(root->data);
        return;
    }
    
    if (root->left) addLeaves(root->left, ans);
    if (root->right) addLeaves(root->right, ans);
}

void addRightBoundary(TreeNode<int>* root, vector<int>& ans) {
    TreeNode<int>* curr = root->right;
    vector<int> temp; 
    while (curr) {
        if (curr->left != NULL || curr->right != NULL) {
            temp.push_back(curr->data);  
        }
        if (curr->right) curr = curr->right; 
        else curr = curr->left;              
    }
    
    for (int i = temp.size() - 1; i >= 0; i--) {
        ans.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int> *root) {
    vector<int> ans;
    
    if (!root) return ans;  // Empty tree
    
    if (root->left != NULL || root->right != NULL) {
        ans.push_back(root->data);
    }

    addLeftBoundary(root, ans);

    addLeaves(root, ans);

    addRightBoundary(root, ans);

    return ans;
}
