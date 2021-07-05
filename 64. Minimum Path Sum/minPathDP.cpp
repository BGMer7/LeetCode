#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> dp(r, vector<int>(c, 0));
        dp[0][0] = grid[0][0];
        for (int i(1); i < r; ++i)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i(1); i < c; ++i)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i(1); i < r; ++i)
        {
            for (int j(1); j < c; ++j)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[r - 1][c - 1];
    }

    int minPathSumDP(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 && j == 0)
                {
                    dp[j] = grid[i][j];
                }
                else if (i == 0)
                {
                    dp[j] = dp[j - 1] + grid[i][j];
                }
                else if (j == 0)
                {
                    dp[j] = dp[j] + grid[i][j];
                }
                else
                {
                    dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
                }
            }
        }
        return dp[n - 1];
    }
};

int main()
{
    vector<vector<int>> grid{{1, 2, 3}, {4, 5, 6}};
    Solution sol;
    int res;
    res = sol.minPathSumDP(grid);
    cout << res;
}