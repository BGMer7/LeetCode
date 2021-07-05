#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        // sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int> &nums, int index)
    {
        if (index == nums.size())
        {
            res.push_back(nums);
            return;
        }

        for (int i(index); i < nums.size(); i++)
        {
            sort(nums.begin() + index, nums.end());
            if (i > index && nums[i] == nums[i - 1])
                continue;
            swap(nums[i], nums[index]);
            dfs(nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }
};
// 注意sort的位置，错误案例[0,0,0,1,9]只要是出现多个连续相同数字，就有可能被切割为[0,1,0,9,0]的样子，所以每次做之前都要排序。

int main()
{
    vector<int> nums{1,2,3};
    Solution sol;
    sol.permuteUnique(nums);
}