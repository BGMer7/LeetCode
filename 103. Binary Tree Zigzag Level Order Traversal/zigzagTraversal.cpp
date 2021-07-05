#include <vector>
#include <queue>
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
    vector<vector<int>> res;
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) // 锯齿遍历
    {
        if (!root)
            return res;
        queue<TreeNode *> q;
        q.emplace(root);
        bool odd = false;
        while (!q.empty())
        {
            if (!odd)
            {
                int size = q.size();
                vector<int> temp(size);
                for (int i(0); i < size; i++)
                {
                    TreeNode *node = q.front();
                    q.pop();
                    temp[i] = node->val;
                    if (node->left)
                        q.emplace(node->left);
                    if (node->right)
                        q.emplace(node->right);
                }
                res.push_back(temp);
            }
            else
            {
                int size = q.size();
                vector<int> temp(size);
                for (int i(0); i < size; i++)
                {
                    TreeNode *node = q.front();
                    q.pop();
                    temp[size - 1 - i] = node->val;
                    if (node->left)
                        q.emplace(node->left);
                    if (node->right)
                        q.emplace(node->right);
                }
                res.push_back(temp);
            }
            odd = !odd;
        }
        return res;
    }
};

int main() {}