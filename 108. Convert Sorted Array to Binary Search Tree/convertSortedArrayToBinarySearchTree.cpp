#include <iostream>
#include <vector>

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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return build(0, nums.size(), nums);
    }

    TreeNode *build(int left, int right, vector<int> &nums)
    {
        if (left >= right)
            return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode *p = new TreeNode(nums[mid]);
        p->left = build(left, mid - 1, nums);
        p->right = build(mid, right, nums);
        return p;
    }
};

int main()
{
}