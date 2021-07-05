#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {     
        vector<int> dp(amount + 1);
        dp[0]= 1;
        for (auto coin : coins)
            for (int i(0); i <= amount; ++i)
                if (i - coin >= 0)
                {
                    dp[i] += dp[i - coin];
                    for (auto s : dp)
                    {
                        cout << s << " ";
                    }
                    cout << endl;
                }
        return dp[amount];
    }
};

int main()
{
    vector<int> coins{2,3,5};
    Solution sol;
    cout << sol.change(10, coins);
}