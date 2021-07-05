#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.size(), n = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3)
            return false;
        dp[0][0] = true;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        int i = 0;
        while (s1[i] == s3[i])
        {
            dp[i + 1][0] = true;
            ++i;
        }
        i = 0;
        while (s2[i] == s3[i])
        {
            dp[0][i + 1] = true;
            ++i;
        }

        for (int i(1); i <= m; ++i)
        {
            for (int j(1); j <= n; ++j)
            {
                dp[i][j] = (dp[i - 1][j] && s1[i+j-1] == s3[i-1]) || (dp[i][j - 1] && s2[i+j-1] == s3[j-1])
            }
        }
        return dp[m][n];
    }
};