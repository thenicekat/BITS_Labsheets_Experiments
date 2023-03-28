// We use recursion, keep finding roots and the parts which are to the left and
// which are to the right and continue :)
// Like the logic is the first element in preorder is always the root
// And we iterate in the inorder until we find the root, every node to the left will
// be in the left sub tree and every node to the right will be in the right sub tree

// So the final logic is we have both inorder and preorder traversals
// Inorder tells us which nodes are to the left and which are to the right
// Preorder gives us the starting or the root node in the tree
// So we can say we go through all the elements in the preorder 
// root->left will contain all elements to the left of the inorder and root->right will contain the right 

#include <iostream>
#include <math.h>
#include <map>
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

TreeNode *recursive_add_to_node(map<int, int> inorder, int *preorder, int start, int end, int *tracker)
{
    // we check if the start and end are same for the inorder array
    if (start >= end)
    {
        return NULL;
    }

    // We assign root to the value of start from preorder list
    TreeNode *root = new TreeNode(preorder[(*tracker)++]);

    // We iterate over inorder until we get the same value
    int counter = inorder[root->val];

    // call the function onto the left and right nodes;
    root->left = recursive_add_to_node(inorder, preorder, start, counter, tracker);

    root->right = recursive_add_to_node(inorder, preorder, counter + 1, end, tracker);

    return root;
}

int get_height_of_tree(TreeNode* root)
{
    if(root == NULL){
        return 0;
    }
    return max(get_height_of_tree(root->left), get_height_of_tree(root->right)) + 1;
}

int main()
{
    freopen("Inputs/B.txt", "r", stdin);
    int counter;
    cin >> counter;

    int preorder[counter];
    int inorder[counter];
    map<int, int> inorder_map;

    for (int i = 0; i < counter; i++)
    {
        cin >> preorder[i];
    }
    for (int i = 0; i < counter; i++)
    {
        cin >> inorder[i];
        inorder_map[inorder[i]] = i;
    }

    int tracker = 0;
    TreeNode *root = recursive_add_to_node(inorder_map, preorder, 0, counter, &tracker);

    // Need to find height of tree, because we need to make an array to store elements :)
    int h = get_height_of_tree(root);
    
    int length = pow(2, h) - 1;

    TreeNode* result[length];
    result[0] = root;

    // We loop till we reach leaves which happens to be 
    for(int i=0; i<length/2; i++){
        if(2*i + 1 <= length) result[2*i + 1] = result[i]->left;
        if(2*i + 2 <= length) result[2*i + 2] = result[i]->right;
    }

    //length = 7
    //0 -> 1 and 2
    //1 -> 3 and 4
    //2 -> 5 and 6
    //3 -> 7 and 8

    for(auto x: result){
        if(x != nullptr) cout << x->val << " ";
        else cout << "-1 ";
    }
    cout << endl;
}