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

TreeNode *makeBeautiful(TreeNode *root, int l, int r){
    if(!root)
            return root;
        
        if(root -> val < l){
            return makeBeautiful(root -> right, l, r);
        }

        else if(root -> val > r){
            return makeBeautiful(root -> left, l, r);
        }

        root -> left = makeBeautiful(root -> left, l, r);
        root -> right = makeBeautiful(root -> right, l, r);

        return root;
}

void printPostOrder(TreeNode* root){
    if(!root) return;

    printPostOrder(root -> left);
    printPostOrder(root -> right);
    cout << root -> val << " ";
}

int main(){
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    TreeNode* root = array_to_tree(a, 1);

    root = makeBeautiful(root, l, r);

    printPostOrder(root);

    destroy_tree(root);

    return 0;
}