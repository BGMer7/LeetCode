#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int n) // 4的幂
    {
        if (n < 0)
            return false;
        if (n == 1)
            return true;
        return !(n & (n - 1)) && (n & 1431655765);
    }
};

int main(){
    bool res;
    Solution sol;
    cout << sol.isPowerOfFour(16);
}