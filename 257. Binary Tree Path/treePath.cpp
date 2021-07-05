#include <iostream>
#include <vector>
#include <string>

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
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        string s("");
        path(root, s, res);
        return res;
    }

    void path(TreeNode *root, string &s, vector<string> &res)
    {
        if (root != nullptr)
        {
            s += to_string(root->val);
            if (root->left == nullptr && root->right == nullptr)
            {
                res.push_back(s);
            }
            else
            {
                s += "->";
                path(root->left, s, res);
                path(root->right, s, res);
            }
        }
    }
};

int main()
{
}