#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{

    cout << "enter the value for Node:" << endl;

    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    // step1 : create Node
    Node *root = new Node(data);

    // step2 : create left node
    cout << "left of Node " << root->data << endl;
    root->left = createTree();

    // step2 : create right node
    cout << "right of Node " << root->data << endl;
    root->right = createTree();

    return root;
}

void preOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    // L
    preOrderTraversal(root->left);
    // R
    preOrderTraversal(root->right);
}

void InOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // L
    InOrderTraversal(root->left);

    cout << root->data << " ";

    // R
    InOrderTraversal(root->right);
}

void PostOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // L
    PostOrderTraversal(root->left);
    // R
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}

// user marker so that we print level order line by line and here marker is null
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (q.size() > 1)
    {

        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            q.push(NULL);
        }
        else
        {

            cout << front->data << " ";

            if (front->left != NULL)
            {
                q.push(front->left);
            }

            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}

int main()
{

    Node *root = createTree();

    // preOrderTraversal(root);
    // InorderTraversal(root);
    // PostOrderTraversal(root);
    levelOrderTraversal(root);
}