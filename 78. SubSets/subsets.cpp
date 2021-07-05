#include <vector>
#include <iostream>

using namespace std;

class Solution
{
private:
    vector<int> tmp;
    vector<vector<int>> res;

    void dfs(int index, vector<int> &nums)
    {
        if (index == nums.size())
        {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[index]);
        dfs(index + 1, nums);
        tmp.pop_back();
        dfs(index + 1, nums);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs(0, nums);
        return res;
    }
};

class SolutionRecur
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> nullVec{};
        vector<vector<int>> ans;
        ans.push_back(nullVec);
        for (int i(0); i < nums.size(); ++i)
        {
            vector<vector<int>> temp = ans;
            for (auto &vec : temp)
            {
                vec.push_back(nums[i]);
                ans.push_back(vec);
            }
        }
        return ans;
    }

    void printVec(vector<int> nums)
    {
        for (auto num : nums)
            cout << num << " ";
        cout << endl;
    }
};

class SolutionReview0602
{
public:
    vector<int> temp;
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs(0, nums);
        return res;
    }

    void dfs(int index, vector<int> &nums)
    {
        if (index == nums.size())
        {
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[index]); // 先算把元素放进来的情况，这样子会先输出全排列。
        dfs(index + 1, nums);
        temp.pop_back();
        dfs(index + 1, nums);

        dfs(index + 1, nums); // 先算把元素都不放进来的情况，这样子会先输出空集。
        temp.push_back(nums[index]);
        dfs(index + 1, nums);
        temp.pop_back();
    }
};

int main()
{
    vector<int> nums{1, 2, 3, 4};
    Solution sol;
    vector<vector<int>> ans;
    ans = sol.subsets(nums);
}
