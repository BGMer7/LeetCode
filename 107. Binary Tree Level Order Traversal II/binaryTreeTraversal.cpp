#include <vector>
#include <queue>
#include <stack>
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
    stack<vector<int>> s;
    vector<vector<int>> res;
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            while (size--)
            {
                TreeNode *num = q.front();
                level.push_back(num->val);
                q.pop();
                if (num->left)
                    q.push(num->left);
                if (num->right)
                    q.push(num->right);
            }
            s.push(level);
        }
        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};

int main() {}