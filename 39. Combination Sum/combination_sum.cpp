#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class SolutionNoRepeat // 每个数字只选用一次
{
public:
    vector<int> tmp;
    vector<vector<int>> res;
    vector<vector<int>> targetSum;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        dfs(0, candidates);
        for (int i(0); i < res.size(); i++)
        {
            if (accumulate(res[i].begin(), res[i].end(), 0) == target)
                targetSum.push_back(res[i]);
        }
        return targetSum;
    }

    void dfs(int index, vector<int> &candidates)
    {
        if (index == candidates.size())
        {
            res.push_back(tmp);
            return;
        }
        tmp.push_back(candidates[index]);
        dfs(index + 1, candidates);
        tmp.pop_back();
        dfs(index + 1, candidates);
    }
};

class Solution // 数字可以重复选用，但是结果要保证唯一性
{
public:
    vector<int> tmp;
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        dfs(candidates, target, 0);
        return res;
    }

    void dfs(vector<int> &candidates, int target, int index)
    {
        if (!target)
        {
            res.push_back(tmp);
            return;
        }

        if (target < 0)
            return; // 说明这个组合的和已经大于target

        for (int i(index); i < candidates.size(); i++)
        {
            tmp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i); // 这里的最后一个参数为i，如果是index，就会出现重复，因为i在增，所以不会重复
            tmp.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1,2,3,6};
    sol.combinationSum(nums, 6);
}