#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    unordered_map<int, int> map;

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i(0); i < inorder.size(); ++i)
            map[inorder[i]] = i;

        int treeSize = inorder.size();
        TreeNode *root = buildHelper(preorder, 0, treeSize, inorder, 0, treeSize);
        return root;
    }

    TreeNode *buildHelper(vector<int> &preorder, int pre_left, int pre_right, vector<int> &inorder, int in_left, int in_right)
    {
        if (pre_left == pre_right)
            return nullptr;

        int root_val = preorder[pre_left];
        TreeNode *root = new TreeNode(root_val);
        int root_index = map[root_val];
        int left_tree_length = root_index - in_left;
        root->left = buildHelper(preorder, pre_left + 1, pre_left + left_tree_length + 1, inorder, in_left, root_index);
        root->right = buildHelper(preorder, pre_left + left_tree_length + 1, pre_right, inorder, root_index + 1, in_right);
        return root;
    }
};

int main() {}