#include <iostream>
#include <vector>
#include <unordered_map>
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

class Solution
{
private:
    unordered_map<int, int> rootMap;

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i(0); i < inorder.size(); ++i)
            rootMap[inorder[i]] = i;

        int sz = inorder.size();
        TreeNode *root = helper(inorder, 0, sz, postorder, 0, sz); // 其实这里是一个关键，第二次做的时候才意识到
        // 这里不能取闭区间，如果取闭区间，那么post_start==post_end就会返回nullptr
        return root;
    }

    TreeNode *helper(vector<int> &inorder, int in_start, int in_end, vector<int> &postorder, int post_start, int post_end)
    {
        if (post_start == post_end)
            return nullptr;

        int root_index = rootMap[postorder[post_end - 1]], left_tree_length = root_index - in_start;
        TreeNode *root = new TreeNode(inorder[root_index]);

        root->left = helper(inorder, in_start, root_index, postorder, post_start, post_start + left_tree_length);
        root->right = helper(inorder, root_index + 1, in_end, postorder, post_start + left_tree_length, post_end - 1);
        return root;
    }
};

int main() {}