// Me dumb, apparently inorder always gives you a sorted list :)
// should have known this before midsems
// legit regret life right now

// ok inorder is wrong because time complexity will o(all number of nodes)
// sad

// ok so here the logic is we go in order till rhe right most
// and then start iterating backwards until the counter becomes 0

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

TreeNode *convert_to_tree(int *arr, int index, int max)
{
    TreeNode *root = nullptr;
    if (index < max && arr[index] != -1)
    {
        root = new TreeNode(arr[index]);
        root->left = convert_to_tree(arr, 2 * index + 1, max);
        root->right = convert_to_tree(arr, 2 * index + 2, max);
    }
    return root;
}

void inorder(TreeNode *root, int *answerCounter, int* found)
{
    // if root is null return
    if (root == nullptr || *found == 1) return;

    // go to the right nodes
    inorder(root->right, answerCounter, found);

    //Check if the answer counter is 0
    if (--(*answerCounter) == 0)
    {
        cout << "Answer: " << root->val << endl;
        *found = 1;
    }
    else
    {
        inorder(root->left, answerCounter, found);
    }
}

int main()
{
    freopen("Inputs/E.txt", "r", stdin);

    int counter;
    cin >> counter;

    int input[counter];
    for (int i = 0; i < counter; i++)
    {
        cin >> input[i];
    }

    int t;
    cin >> t;

    TreeNode *tree = convert_to_tree(input, 0, counter);

    int found = 0;
    inorder(tree, &t, &found);
}