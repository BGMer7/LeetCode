#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        if (n == 0)
            return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i(2); i <= n; ++i)
        {
            dp[i] = dp[i / 2] + i % 2 * dp[i / 2 + 1];
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {}