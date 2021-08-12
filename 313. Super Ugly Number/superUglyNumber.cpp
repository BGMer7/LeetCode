#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        vector<int> dp(n + 1);
        dp[1] = 1;
        const int len = primes.size();
        vector<int> ptr(len, 1);
        for (int i(2); i < n + 1; ++i)
        {
            int minNum = INT_MAX;
            for (int j(0); j < len; ++j)
            {
                minNum = min(minNum, primes[j] * dp[ptr[j]]);
            }
            dp[i] = minNum;
            for (int j(0); j < len; ++j)
            {
                if (dp[i] == primes[j] * dp[ptr[j]])
                    ++ptr[j];
            }
        }
        return dp[n];
    }
};

int main() {}