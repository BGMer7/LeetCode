#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> tmp;
    vector<vector<int>> res;

    void dfs(int index, vector<int> &nums)
    {
        res.push_back(tmp);
        if (index >= nums.size())
            return;
        for (int i(index); i < nums.size(); ++i)
        {
            if (i > index && nums[i - 1] == nums[i])
                continue;

            tmp.push_back(nums[i]);
            dfs(i+1, nums);
            tmp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        dfs(0, nums);
        return res;
    }
};