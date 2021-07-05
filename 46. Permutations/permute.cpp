#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int> &nums)
    {
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int> &nums, int index)
    {
        if (index == nums.size()) // 说明index已经遍历到了最后一个数字
        {
            res.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); ++i)
        {
            swap(nums[i], nums[index]);
            dfs(nums, index + 1);
            swap(nums[i], nums[index]);
        }
    }
};

int main()
{
    vector<int> nums{1, 2, 3};
    Solution sol;
    vector<vector<int>> res = sol.permute(nums);
    cout << res.size() << endl;
}