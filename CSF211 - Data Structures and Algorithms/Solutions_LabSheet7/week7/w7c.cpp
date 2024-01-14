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

void destroy_tree(TreeNode *root)
{
    if (root->left)
        destroy_tree(root->left);
    if (root->right)
        destroy_tree(root->right);
    delete root;
}

int countFreedom(TreeNode *root, int rem)
{
    if (!root)
        return 0;
    rem -= root->val;
    if (rem < 0)
        return 0;
    if (!rem and !root->left and !root->right)
        return 1;
    return countFreedom(root->left, rem) + countFreedom(root->right, rem);
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    TreeNode *root = array_to_tree(a, 1);
    cout << countFreedom(root, x) << "\n";
    destroy_tree(root);

    return 0;
}