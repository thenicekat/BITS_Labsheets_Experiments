#include <bits/stdc++.h>
#include <cstddef>
#include <utility>

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

TreeNode* findAncestor(TreeNode* root, int x, int y){
    if(!root)
        return NULL;
    
    if(root -> val == x || root -> val == y)
        return root;
    
    TreeNode *l = findAncestor(root -> left, x, y);
    TreeNode *r = findAncestor(root -> right, x, y);
    
    if(l && r)
        return root;
    
    if(l)
        return l;
    
    return r;
}

int main(){
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    TreeNode* root = array_to_tree(a, 1);

    TreeNode* anc = findAncestor(root, x, y);
    cout << anc -> val << endl;
    destroy_tree(root);

    return 0;
}