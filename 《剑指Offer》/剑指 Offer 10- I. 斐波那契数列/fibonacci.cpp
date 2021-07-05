#include <iostream>
class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int prev1 = 0, prev2 = 1, sum = 0;
        n -= 1;
        while (n--)
        {
            sum = (prev1 + prev2) % 1000000007;
            prev1 = prev2;
            prev2 = sum;
        }
        return sum;
    }
};

int main() {
    int n = 7;
    Solution sol;
    std::cout << sol.fib(n) << std::endl;

}