#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
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
    vector<tuple<int, int, int>> bias;

    void dfs(int row, int col, TreeNode *root)
    {
        if (!root)
            return;
        bias.emplace_back(row, col, root->val);

        dfs(row + 1, col - 1, root->left);
        dfs(row + 1, col + 1, root->right);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        dfs(0, 0, root);
        sort(bias.begin(), bias.end(), [](tuple<int, int, int> a, tuple<int, int, int> b)
             {
                 // return get<1>(a)==get<1>(b)?get<0>(a)<get<0>(b):get<1>(a)<get<1>(b);
                 if (get<1>(a) != get<1>(b))
                     return get<1>(a) < get<1>(b);
                 if (get<0>(a) == get<0>(b))
                     return get<2>(a) < get<2>(b);
                 return get<0>(a) < get<0>(b);
             });
        // sort(bias.begin(), bias.end());
        int colCurr = INT_MIN;
        vector<vector<int>> res;
        for (const auto &[row, col, val] : bias)
        {
            if (col != colCurr)
            {
                res.emplace_back();
                colCurr = col;
                res.back().emplace_back(val);
            }
            else
            {
                res.back().emplace_back(val);
                continue;
            }
        }
        return res;
    }
};

int main() {}