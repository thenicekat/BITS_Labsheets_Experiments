// We observe that all numbers to the right of
// node are greater than the node itself
// So if we start iterating from the root
// We recursively go to the right most node and start backtracking
// So we go to 8->7->6->5->4->3->2->1->0
// So like if we write some sort of pseudo code
// recursive_traverse(root):
//  if(root->right != nullptr) recusive_traverse(root->right);
//  sum += root->value;
//  if(root->left != nullptr) recusive_traverse(root->left);

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

TreeNode *convert_to_tree(int *array, int index, int max)
{
    TreeNode *root = nullptr;
    if (index < max && array[index] != -1)
    {
        root = new TreeNode(array[index]);
        root->left = convert_to_tree(array, 2 * index + 1, max);
        root->right = convert_to_tree(array, 2 * index + 2, max);
    }
    return root;
}

void bst_to_gst(TreeNode *root, int *tracker)
{
    // First we go to the right sub tree nodes
    if (root->right != nullptr)
        bst_to_gst(root->right, tracker);
    // Then to the current node itself
    (*tracker) += root->val;
    // Then we assign the value to the node
    root->val = *tracker;
    // Then iterate through the left sub trees
    if (root->left != nullptr)
        bst_to_gst(root->left, tracker);
}

int main()
{
    freopen("Inputs/D.txt", "r", stdin);
    int counter;
    cin >> counter;

    int input[counter];

    for (int i = 0; i < counter; i++)
    {
        cin >> input[i];
    }

    TreeNode *tree = convert_to_tree(input, 0, counter);

    int tracker = 0;
    bst_to_gst(tree, &tracker);

    int length = counter;
    TreeNode *array[length];
    array[0] = tree;
    for (int i = 0; i < length / 2; i++)
    {
        // if (array[i] == nullptr)
        // {
        //     array[2 * i + 1] = nullptr;
        //     array[2 * i + 2] = nullptr;
        // }
        // else
        // {
            if (2 * i + 1 < counter)
                array[2 * i + 1] = array[i]->left;
            if (2 * i + 2 < counter)
                array[2 * i + 2] = array[i]->right;
        // }
    }

    for (auto x : array)
    {
        if (x == nullptr)
        {
            cout << -1 << " ";
        }
        else
            cout << x->val << " ";
    }
}
