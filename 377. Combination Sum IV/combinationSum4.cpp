#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        //vector<int> dp(target + 1);
        int dp[target+1];
        dp[0] = 1;
        for (int i(1); i <= target; ++i)
        {
            for (auto num : nums)
            {
                if (i >= num)
                    dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};

int main()
{
    vector<int> dp(4);
    int dd[4];
    cout << sizeof(dp) << sizeof(dd);
}