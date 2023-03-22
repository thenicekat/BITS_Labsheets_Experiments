// Me dumb, apparently inorder always gives you a sorted list :)
// should have known this before midsems 
// legit regret life right now

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

TreeNode* convert_to_tree(int* arr, int index, int max){
    TreeNode* root = nullptr;
    if(index < max && arr[index] != -1){
        root = new TreeNode(arr[index]);
        root->left = convert_to_tree(arr, 2*index + 1, max);
        root->right = convert_to_tree(arr, 2*index + 2, max);
    }
    return root;
}

void inorder(TreeNode* root, int *result, int* counter){
    if(root == nullptr) return;
    inorder(root->left, result, counter);
    result[(*counter)++] = root->val;
    inorder(root->right, result, counter);
}

int main(){
    freopen("Inputs/E.txt", "r", stdin);
    int counter;
    cin >> counter;
    
    int input[counter];
    for (int i = 0; i < counter; i++){
        cin >> input[i];
    }

    int t;
    cin >> t; 

    TreeNode* tree = convert_to_tree(input, 0, counter);
    
    int temp_counter = 0;
    int array[counter];
    inorder(tree, array, &temp_counter);

    cout << array[temp_counter - t];
}