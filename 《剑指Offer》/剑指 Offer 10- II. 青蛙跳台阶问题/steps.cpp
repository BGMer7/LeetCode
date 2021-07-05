#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int numWays(int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i(3); i < n + 1; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
            dp[i] %= 1000000007;
        }
        return dp[n];
    }
};

int main() {
    int n =44;
    Solution sol;
    cout << sol.numWays(n);
}