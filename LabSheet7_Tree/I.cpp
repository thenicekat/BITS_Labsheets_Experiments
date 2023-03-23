// I think we just recursively traverse
// We can probably keep track of the elements in a vector :)
#include <vector>
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

TreeNode *construct_tree(int *arr, int index, int max)
{
    TreeNode *root = nullptr;
    if (index < max && arr[index] != -1)
    {
        root = new TreeNode(arr[index]);
        root->left = construct_tree(arr, 2 * index + 1, max);
        root->right = construct_tree(arr, 2 * index + 2, max);
    }
    return root;
}

int find_path(TreeNode *root, vector<int> &in, int value)
{
    // Check if root is null, then return 0
    if (root == nullptr)
        return 0;

    // Then send the value into the vector
    in.push_back(root->val);

    // If the value is the needed one, return 1
    if (root->val == value)
        return 1;

    // Otherwise we need to go to other paths :)
    // We check if the node exists in the left or right path
    if (find_path(root->left, in, value) || find_path(root->right, in, value))
    {
        return 1;
    }

    // If not there
    in.pop_back();
    return 0;
}

int main()
{
    freopen("Inputs/I.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int length, node_a, node_b;
        cin >> length >> node_a >> node_b;

        int input[length];
        for (int i = 0; i < length; i++)
        {
            cin >> input[i];
        }

        TreeNode *tree = construct_tree(input, 0, length);

        vector<int> path_a, path_b;
        find_path(tree, path_a, node_a);
        find_path(tree, path_b, node_b);

        int index = 0, answer;
        while(path_a[index] == path_b[index]){
            answer = path_a[index];
            index++;
        }

        cout << answer << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}