#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n) // 2的幂
    {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

int main()
{
    Solution sol;
    for (int i(0); i < 10; ++i)
    {
        cout << sol.isPowerOfTwo(i) << endl;
    }
}