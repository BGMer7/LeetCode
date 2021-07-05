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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i(0); i < inorder.size(); ++i)
            rootMap[inorder[i]] = i;
        int tree_size = preorder.size();
        return helper(preorder, 0, tree_size, inorder, 0, tree_size);
    }

    TreeNode *helper(vector<int> &preorder, int pre_start, int pre_end, vector<int> &inorder, int in_start, int in_end)
    {
        if (pre_start == pre_end)
            return nullptr;

        // 因为是preorder一个一个遍历过去的，先序遍历就是先遍历根节点，所以根节点就是pre_start
        int root_val = preorder[pre_start];
        TreeNode *root = new TreeNode(root_val);

        // 在中序遍历中找到这个根节点，将inorder分成两部分，左边是左子树，右边是右子树
        int root_index = rootMap[root_val];
        int left_tree_length = root_index - in_start;
        root->left = helper(preorder, pre_start + 1, pre_start + left_tree_length + 1, inorder, in_start, root_index);
        root->right = helper(preorder, pre_start + left_tree_length + 1, pre_end, inorder, root_index + 1, in_end);

        return root;
    }
};

int main(){
    
}