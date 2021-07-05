#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX); // 每个数的最优解都存在result数组里
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; i - j * j >= 0; j++)
            {                                          // 观察比N小的数，且符合N = IxI + N'的数值
                dp[i] = min(dp[i], dp[i - j * j] + 1); // 把最优解（最小值）+ 1 写入result
            }
        }
        return dp[n];
    }
};

int main()
{
    int a = 0x7FFFFFFF;
    int b = INT_MAX;
    if (a == b)
        cout << "r";
}