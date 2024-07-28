// Height of BST  - D
// Diameter of BST  1) fast method -D
// validate the BST -D 
// LCA  of BST for p,q node -D 
// Kth smallest element -D
// create BST from the InOrder traversal -D
// convert BST into Balanced BST -D
//  2-sum in BST -D

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Function to find the height of a binary tree.
    int height(struct Node *node)
    {

        // base case
        if (node == NULL)
            return 0;

        int left = height(node->left);
        int right = height(node->right);

        return max(left, right) + 1;
    }
};

int main()
{
}