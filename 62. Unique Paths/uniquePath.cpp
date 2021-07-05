#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m == 1)
            return 1;
        if (m == 2)
            return n;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i(1); i < n; ++i)
            dp[0][i] = 1;
        for (int i(1); i < m; ++i)
            dp[i][0] = 1;

        for (int i(1); i < m; ++i)
            for (int j(1); j < n; ++j)
                dp[i][j]= dp[i-1][j]+dp[i][j-1];

        return dp[m-1][n-1];
    }
};

int main()
{
    int m = 3, n = 7;
    Solution sol;
    int res = sol.uniquePaths(m, n);
    cout << res;
}