#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
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
    priority_queue<int, vector<int>, greater<int>> q;

public:
    int findSecondMinimumValue(TreeNode *root)
    {
        dfs(root);
        const int minest = q.top();
        int res = minest;
        while (!q.empty() && q.top() == minest)
        {
            q.pop();
            res = q.top();
        }
        return res == minest ? -1 : res;
    }

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        else
            q.push(root->val);

        dfs(root->left);
        dfs(root->right);
    }
};

int main() {}