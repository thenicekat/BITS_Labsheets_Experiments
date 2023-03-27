// This is definitely a stack and backtracking type question
// Here we need to add all the nodes onto stack and maybe use recursion or looping
// to backtrack such that you get all possible sums
// sort of we are doing DFS :)

// The final logic is that we go through all the possible paths in 
// hope of finding the path where it becomes zero at the leaf
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

TreeNode* construct_tree(int* arr, int i, int max){
    TreeNode* root = nullptr;
    if(i < max){
        if(arr[i] != -1){
            root = new TreeNode(arr[i]);
            root->left = construct_tree(arr, 2*i + 1, max);
            root->right = construct_tree(arr, 2*i + 2, max);
        }
    }
    return root;
}

void traverse_root(TreeNode* root, int sum, int* counter){
    if(root->left == nullptr && root->right == nullptr){
        // Means you are at a leaf
        if(sum-root->val == 0){
            *counter += 1;
        }
    }
    if(root->left != nullptr) traverse_root(root->left, sum-root->val, counter);
    if(root->right != nullptr) traverse_root(root->right, sum-root->val, counter);
    return;
}

int main(){
    freopen("Inputs/C.txt", "r", stdin);
    int counter, sumNeeded;
    cin >> counter >> sumNeeded;

    int tree_input[counter];

    for (int i = 0; i < counter; i++){
        cin >> tree_input[i];
    }

    TreeNode* root = construct_tree(tree_input, 0, counter);

    int answer = 0;
    traverse_root(root, sumNeeded, &answer);
    cout << "The Number of Paths is: " << answer << endl;
}