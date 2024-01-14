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

void kthLargest(TreeNode *root, int &k, int &ans)
{
    if (!root or ans != -1)
        return;
    kthLargest(root->right, k, ans);
    if (ans == -1) {
        if (k == 1) {
            ans = root->val;
        } else {
            k--;
            kthLargest(root->left, k, ans);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int k;
    cin >> k;

    TreeNode *root = array_to_tree(a, 1);
    int ans = -1;
    kthLargest(root, k, ans);
    cout << ans << "\n";

    destroy_tree(root);

    return 0;
}