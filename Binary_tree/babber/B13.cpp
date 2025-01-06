
// Transform to Sum Tree : https://www.geeksforgeeks.org/problems/transform-to-sum-tree/1

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        // Your code here
        sum(node);
    }
    
    
    int sum(Node* root){
        
        if(root == NULL) return 0;
        
        // if root is the leaf node
        
        if(root-> left == NULL && root-> right == NULL){
             
             int temp = root->data;
             
             root->data = 0;
             
             return temp;
        }
        
        
        int left_sum = sum(root->left);
        
        int right_sum = sum(root->right);
        
        
        int curr_val = root->data;
        
        root->data = left_sum + right_sum;
        
        // total sum devo pade ne 
        return left_sum + right_sum + curr_val;
          
    }
    
};