// Even though it looks fancy and sounds complicated
// The fact that it is a binary search tree makes it easy
// I mean in a binary search tree, every node to the right has higher value
// and every node to the left has lower value

// now this is a little bit hard question, we have to recursively travel until we can
// remove those nodes which are higher than the given limit and lower than the given limit
#include <iostream>
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

TreeNode* createTree(int* array, int index, int max){
    TreeNode* root = nullptr;
    if(index < max && array[index] != -1){
        root = new TreeNode(array[index]);
        root->left = createTree(array, 2*index + 1, max);
        root->right = createTree(array, 2*index + 2, max);
    }
    return root;
}

void postOrderTraverse(TreeNode* node){
    if(node == nullptr) return;
    postOrderTraverse(node->left);
    postOrderTraverse(node->right);
    cout << node->val << " ";
}

TreeNode *beauty(TreeNode * root,int l,int r)
{
    if(root==NULL)
    return NULL;

    if(root->val >=l && root->val <=r)
    {
        root->left = beauty(root->left,l,r);
        root->right = beauty(root->right,l,r);
    }
    else if(root->val >=l && root->val >r)
    {
        root = beauty(root->left,l,r);
    }
    else if(root->val<l && root->val <=r)
    {
        root = beauty(root->right,l,r);
    }

    return root;
}

int main(){
    freopen("Inputs/H.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++){
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int size, lowLim, highLim;
        cin >> size >> lowLim >> highLim;

        int input[size];
        for(int i=0; i<size; i++){
            cin >> input[i];
        }

        cout << "Lower Limit: " << lowLim << endl;
        cout << "Higher Limit: " << highLim << endl;

        TreeNode* tree = createTree(input, 0, size);

        tree = beauty(tree, lowLim, highLim);
        
        postOrderTraverse(tree);
        cout << endl;

        cout << "--------- END TEST CASE " << " ---------" << endl;
    }
}