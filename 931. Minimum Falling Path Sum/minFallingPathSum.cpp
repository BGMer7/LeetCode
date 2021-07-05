#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (n == 1)
            return matrix[0][0];
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0] = matrix[0];
        for (int i(1); i < n; ++i)
        {
            for (int j(0); j < n; ++j)
            {
                if (j == 0)
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
                else if (j == n - 1)
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + matrix[i][j];
                else
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) + matrix[i][j];
            }
        }
        int minPath = INT_MAX;
        for (int i(0); i < n; ++i)
        {
            if (dp[n - 1][i] < minPath)
                minPath = dp[n - 1][i];
        }
        return minPath;
    }
};

int main()
{
    vector<vector<int>> path{{2,1,3},{6,5,4},{7,8,9}};
    Solution sol;
    int res;
    res = sol.minFallingPathSum(path);
    cout << res;
}