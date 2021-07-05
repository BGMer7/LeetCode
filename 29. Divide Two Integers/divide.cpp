#include <iostream>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        bool isPosi = true;
        if (divisor == 0)
            return -1;
        if (divisor < 0)
        {
            isPosi = !isPosi;
            divisor = -divisor;
        }
        if (dividend < 0)
        {
            isPosi = !isPosi;
            dividend = -dividend;
        }
        int res = 0;
        int sum = 0;
        while (sum + divisor <= dividend)
        {
            sum += divisor;
            // cout << sum << endl;

            ++res;
            // cout << res << endl;
        }
        return isPosi ? res : -res;
    }
};

long mul(long a, long k)
    {
        long ans = 0;
        while (k > 0)
        {
            if ((k & 1) == 1)
                ans += a;
            k >>= 1;
            a <<= 1;
            cout  << ans << endl;
        }
        return ans;
    }

int main()
{
    Solution sol;
    // cout << sol.divide(10, 3);
    cout << mul(100, 1000);

}