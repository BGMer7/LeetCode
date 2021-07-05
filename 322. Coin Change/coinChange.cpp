#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int Max = amount + 1;
        //1、状态数组DP table
        vector<int> dp(amount + 1, Max); //建长为amount+1的数组，且每个元素也初始化为amount+1（因为凑成amount金额的硬币数最多只可能等于amount（全用 1 元面值的硬币）），在遍历时如果金额凑不出则不更新，于是若最后结果仍然是amount + 1，则表示金额凑不出，返回-1
        //2、状态初始化
        dp[0] = 0;
        //3、状态转移
        for (int i = 1; i <= amount; ++i)
        {
            for (int j = 0; j <= coins.size() - 1; ++j)
            {
                if (coins[j] <= i)
                { //为了避免出现dp[2-5]的情况
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                    //和剪绳子一样，加了上一轮j的dp[i]
                    print(dp);
                }
            }
        }
        //4、返回最终状态
        return dp[amount] > amount ? -1 : dp[amount];
    }

    void print(vector<int> &nums)
    {
        for (auto n : nums)
        {
            cout << n << " ";
        }
        cout << endl;
    }
};

int main()
{
    vector<int> coins{1, 2, 5};
    int target = 11;
    Solution sol;
    sol.coinChange(coins, target);
}