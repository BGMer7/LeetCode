#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        // int dp[m + 1][n + 1];
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++)
        {
            char c1 = text1.at(i - 1);
            for (int j = 1; j <= n; j++)
            {
                char c2 = text2.at(j - 1);
                if (c1 == c2)
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

main()
{
    string s1("abcde");
    string s2("ace");
    Solution sol;
    int res = sol.longestCommonSubsequence(s1, s2);
    cout << res;
}