// I think we just recursively traverse
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

TreeNode* construct_tree(int* arr, int index, int max){
    TreeNode* root = nullptr;
    if(index < max && arr[index] != -1){
        root = new TreeNode(arr[index]);
        root->left = construct_tree(arr, 2*index + 1, max);
        root->right = construct_tree(arr, 2*index + 2, max);
    }
    return root;
}

int main(){
    freopen("Inputs/I.txt", "r", stdin);
    int counter, node_a, node_b;
    cin >> counter >> node_a >> node_b;

    int input[counter];
    for (int i = 0; i < counter; i++){
        cin >> input[i];
    }

    TreeNode* tree = construct_tree(input, 0, counter);
    
}