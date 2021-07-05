#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size(), res=INT_MIN;
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        for(int i(1);i<n+1;i++){
            dp[i] = max(dp[i-1]+nums[i-1], nums[i-1]);
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {23, 4, -3, 75, 23, -87};
    cout << sol.maxSubArray(nums) << endl;
}