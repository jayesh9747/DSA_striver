//  diagonal traversal

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

vector<int> diagonal(Node *root)
{
    // your code here

    // take  queue data structure

    queue<Node *> q;

    vector<int> ans;

    if (!root)
        return ans;
    // insert the root first
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        // jab tak right element exist kar raha ho  tab tak waha jate raho
        while (temp)
        {
            // jab  root ke pass left ho to usse queue mai push kardo
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            ans.push_back(temp->data);
            temp = temp->right;
        }
    }

    return ans;
}