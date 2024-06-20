// creating BST From Scratch
// each order print
// max and min value of tree
// Search in BST
// Insert Node in BST
// Delete Node in BST --> @2 methods

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void InsertNodeIntoBST(Node *&root, int val)
{

    if (root == NULL)
    {
        root = new Node(val);
        return;
    }
    else
    {
        if (root->data > val)
        {
            InsertNodeIntoBST(root->left, val);
        }
        else
        {
            InsertNodeIntoBST(root->right, val);
        }
    }
}

void createBST(Node *&root)
{

    int data;

    cout << "Enter the value of Node" << endl;
    cin >> data;

    while (data != -1)
    {
        InsertNodeIntoBST(root, data);

        cout << "Enter the value of Node" << endl;
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{

    queue<Node *> q;

    if (root == NULL)
    {
        return;
    }

    q.push(root);
    q.push(NULL);

    while (q.size() > 1)
    {
        Node *top = q.front();
        q.pop();

        if (top == NULL)
        {
            cout << endl;
            q.push(NULL);
        }

        else
        {
            cout << top->data << " ";

            if (top->left != NULL)
            {
                q.push(top->left);
            }

            if (top->right != NULL)
            {
                q.push(top->right);
            }
        }
    }
}

void PreOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // NLR

    cout << root->data << endl;
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void InOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // NLR
    InOrderTraversal(root->left);
    cout << root->data << endl;
    InOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // NLR
    InOrderTraversal(root->left);
    InOrderTraversal(root->right);
    cout << root->data << endl;
}

Node *MaxInBST(Node *root)
{

    if (root == NULL)
    {
        cout << "There is No Node in the BST";
        return NULL;
    }

    // max always right most element hoga BST ka

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root;
}

Node *MinInBST(Node *root)
{

    if (root == NULL)
    {
        cout << "There is No Node in the BST";
        return NULL;
    }

    // max always right most element hoga BST ka

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

bool SearchInBST(Node *root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == target)
        return true;

    if (root->data < target)
    {
        return SearchInBST(root->right, target);
    }
    else
    {
        return SearchInBST(root->left, target);
    }
}

Node *DeleteNodeInBST(Node *root, int target)
{

    if (root == NULL)
        return NULL;

    if (root->data == target)
    {

        // hamara target element leaf node ho
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // Jab sif Left Child ho
        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            // return left tree
            return temp;
        }

        // Jab sif right Child ho
        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            // return right sub tree
            return temp;
        }

        // Jab dono children ho

        /*
        @@always yaha pe mistake hoti hai usse sahi karna hai
        */

        else
        {
            Node *t = MaxInBST(root->left);

            root->data = t->data;
            root->left = DeleteNodeInBST(root->left, t->data);
        }
    }

    if (root->data < target)
    {
        DeleteNodeInBST(root->right, target);
    }
    else
    {
        DeleteNodeInBST(root->left, target);
    }

    return root;
}

int main()
{
    Node *root = NULL;
    createBST(root);

    cout << "level order Traversal" << endl;
    levelOrderTraversal(root);

    Node *t = MaxInBST(root);
    Node *p = MinInBST(root);

    cout << endl;
    cout << "Max in BST " << t << endl;

    cout << "Min in BST " << p->data << endl;

    int q;
    cout << "Which value you ask to search ?" << endl;
    cin >> q;

    while (q != -1)
    {
        cout << SearchInBST(root, q) << endl;
        cout << "Which value you ask to search ?" << endl;
        cin >> q;
    }
}