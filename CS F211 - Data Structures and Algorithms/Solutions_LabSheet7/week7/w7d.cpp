#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *array_to_tree(vector<int> &a, int i)
{
    if (i > (int)a.size() or a[i - 1] == -1)
        return nullptr;
    TreeNode *root = new TreeNode(a[i - 1]);
    root->left = array_to_tree(a, 2 * i);
    root->right = array_to_tree(a, 2 * i + 1);
    return root;
}

void BST_to_GST(TreeNode *root, int &sum)
{
    if (!root)
        return;
    BST_to_GST(root->right, sum);
    sum += root->val;
    root->val = sum;
    BST_to_GST(root->left, sum);
}

void tree_to_array(TreeNode *root, vector<int> &res, int i)
{
    if (!root)
        return;
    while ((int)res.size() < i)
    {
        res.push_back(-1);
    }
    res[i - 1] = root->val;
    tree_to_array(root->left, res, 2 * i);
    tree_to_array(root->right, res, 2 * i + 1);
    delete root;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    TreeNode *root = array_to_tree(a, 1);
    int sum = 0;
    BST_to_GST(root, sum);

    vector<int> res;
    tree_to_array(root, res, 1);
    for (auto &x : res)
        cout << x << " ";
    cout << "\n";

    return 0;
}