#include <math.h>
#include <iostream>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        if (c == 0)
            return true;
        long long i = 0;
        long long j = sqrt(c);
        long long sum = 0;
        while (i <= j)
        {
            sum = i * i + j * j;
            if (sum == c)
            {
                return true;
            }
            else if (sum > c)
            {
                --j;
            }
            else if (sum < c)
            {
                ++i;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    bool res = sol.judgeSquareSum(2147482647);
    cout << res;
}