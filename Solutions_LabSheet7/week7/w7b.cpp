#include <bits/stdc++.h>

using namespace std;

const int M = 3005;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *constructTree(vector<int> &a, vector<int> &b, vector<int> &idx, int &i, int lb, int rb)
{
    int val = a[i];
    // cout << val << " " << lb << " " << rb << " " << idx[val] << "\n";
    TreeNode *root = new TreeNode(val);
    if (lb < rb)
    {
        i++;
        assert(lb <= idx[val] - 1);
        root->left = constructTree(a, b, idx, i, lb, idx[val] - 1);
        i++;
        assert(idx[val] - 1 <= rb);
        root->right = constructTree(a, b, idx, i, idx[val] + 1, rb);
    }
    return root;
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
    vector<int> b(n);
    for (auto &x : b)
        cin >> x;

    vector<int> idx(M, -1);
    for (int i = 0; i < n; ++i)
        idx[b[i]] = i;

    int i = 0;
    auto root = constructTree(a, b, idx, i, 0, n - 1);
    vector<int> res;
    tree_to_array(root, res, 1);
    for (auto &x : res)
        cout << x << " ";
    cout << "\n";

    return 0;
}