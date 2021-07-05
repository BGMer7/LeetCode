#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <algorithm>

using namespace std;

class Solution // 数字可以重复选用，但是结果要保证唯一性
{
public:
    vector<int> tmp;
    set<vector<int>> resSet;
    // 在39题的基础上，把candidate先排序，不允许重复（i改成i+1），再用set存储一遍结果去重，最后转换为vector
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        vector<vector<int>> resVec;
        resVec.assign(resSet.begin(), resSet.end());
        return resVec;
    }

    void dfs(vector<int> &candidates, int target, int index)
    {
        if (!target)
        {
            resSet.insert(tmp);
            return;
        }

        if (target < 0)
            return; // 说明这个组合的和已经大于target

        for (int i(index); i < candidates.size(); i++)
        {
            tmp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1); // 这里的最后一个参数为i，如果是index，就会出现重复，因为i在增，所以不会重复
            tmp.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1, 2, 3, 6};
    sol.combinationSum2(nums, 6);
}