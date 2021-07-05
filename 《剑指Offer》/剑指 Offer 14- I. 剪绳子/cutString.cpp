#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int cuttingRope(int n)
    {
        if (n <= 3)
            return n - 1;
        vector<int> dp(n + 1);
        dp[2] = 2; // 到2就不要分了，因为直接x2比x1x1要来得大
        dp[3] = 3; // 到3就不要分了，因为直接x3比x1x2要来的大
        // dp[4] = 4; // 1x4 == 2x2
        // dp[5] = 6; // 2x3 > 1x5 要分

        for (int i(4); i < n + 1; ++i)
            for (int j = 1; j <= i / 2; ++j)
                dp[i] = max(dp[i], dp[i - j] * dp[j]);
        return dp[n];
    }
};

int main() {}