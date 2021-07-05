#include <iostream>

using namespace std;

class Solution
{
public:
    double myPow(double x, long n)
    {
        if (x == 0.0 || x == 1.0)
            return x;
        if (n == 0)
            return 1.0;

        double res = 1.0;
        if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }
        while (n)
        {
            if (n % 2)
                res *= x;

            x *= x;
            n = n / 2;
        }
        return res;
    }
};

int main(){
    Solution sol;
    double x = 2.000;
    long n = -2147483648;
    cout << sol.myPow(x,n);
}