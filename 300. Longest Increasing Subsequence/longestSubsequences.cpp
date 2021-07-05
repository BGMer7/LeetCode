#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 1;

        vector<int> dp(n, 1);
        dp[0] = 1;
        int res = INT_MIN;
        for (int i(1); i < n; ++i)
            for (int j(i - 1); j >= 0; --j)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[j] + 1, dp[i]);
                if (dp[i] > res)
                    res = dp[i];
            }
        // int max = INT_MIN;
        // for (auto num : dp){
        //     if (num > max)
        //         max = num;
        // }

        return res;
    }
};

int main()
{
    vector<int> nums { 10, 9, 2, 5, 3, 7, 101, 18 };
    Solution sol;
    int res = sol.lengthOfLIS(nums);
    cout << res;
}