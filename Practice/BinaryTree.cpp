#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left, *right;
    node(int value)
    {
        this->data = value;
        left = right = NULL;
    }
};
node *create()
{
    cout << "Enter the value :(-1 for break) : ";
    int val;
    cin >> val;
    if (val == -1)
        return NULL;
    node *newnode = new node(val);
    cout << "Enter the left child of " << val << ": ";
    newnode->left = create();
    cout << "Enter the right child of " << val << ": ";
    newnode->right = create();
    return newnode;
}
vector<int> LevelOrderTraversal(node *root)
{
    vector<int> ans;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            ans.push_back(q.front()->data);
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
    }
    return ans;
}
void InorderTraversal(node *root)
{
    if (root == NULL)
        return;
    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
}
void PreorderTraversal(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}
void PostorderTraversal(node *root)
{
    if (root == NULL)
        return;
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout << root->data << " ";
}
int isBST(node *root, int mini, int maxi)
{
    if (root == NULL)
        return 1;
    if (root->data <= mini || root->data >= maxi)
        return 0;
    return isBST(root->left, mini, root->data) && isBST(root->right, root->data, maxi);
}
node *insert(node *root, int value)
{
    if (root == NULL)
    {
        node *newnode = new node(value);
        return newnode;
    }
    if (value == root->data)
    {
        cout << "Already Present in the BST\n";
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}
node *InorderPredecessor(node *root)
{
    if (root->right != NULL)
    {
        root = root->right;
        while (root->left != NULL)
            root = root->left;
        return root;
    }
    else if (root->left != NULL)
    {
        root = root->left;
        while (root->right != NULL)
            root = root->right;
        return root;
    }
    return root;
}
node *erase(node *root, int value)
{
    if (root == NULL)
    {
        cout << "Element is not found\n";
        return root;
    }
    if (value > root->data)
    {
        root->right = erase(root->right, value);
    }
    else if (value < root->data)
    {
        root->left = erase(root->left, value);
    }
    else
    {
        node *take = InorderPredecessor(root);
        if (take == root)
        {
            delete root;
            return NULL;
        }
        else if (root->right != NULL)
        {
            root->data = take->data;
            root->right = erase(root->right, root->data);
        }
        else
        {
            root->data = take->data;
            root->left = erase(root->left, root->data);
        }
    }
    return root;
}
int isPresent(node *root, int &value)
{
    if (root == NULL)
        return 0;
    while (root && root->data != value)
    {
        if (value > root->data)
            root = root->right;
        else
            root = root->left;
    }
    return !root == NULL;
}
void show(vector<int> &v)
{
    for (int &i : v)
        cout << i << " ";
    cout << endl;
}
int main()
{
    node *root = create();
    cout << "Inorder : ";
    InorderTraversal(root);
    cout << endl;
    cout << "Preorder : ";
    PreorderTraversal(root);
    cout << endl;
    cout << "Postorder : ";
    // PostorderTraversal(root);
    // cout << endl;
    // cout << isBST(root, INT_MIN, INT_MAX) << endl;
    // root = erase(root, 3);
    vector<int> v = LevelOrderTraversal(root);
    show(v);

    return 0;
}