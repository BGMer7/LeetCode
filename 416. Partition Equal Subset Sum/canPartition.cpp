#include <vector>
#include <iostream>

using namespace std;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto num : nums)
            sum += num;
        if (sum % 2)
            return false;

        int target = sum / 2;
        vector<bool> dp(target + 1);
        dp[0] = true;

        for (auto num : nums)
            for (int i(target); i > 0; --i)
                if (num <= i)
                    dp[i] = dp[i] || dp[i - num];

        return dp[target];
    }
};

int main()
{
    vector<int> nums{3, 3, 3, 4, 5};
    Solution sol;
    bool res;
    res = sol.canPartition(nums);
    cout << res;
}