#include <iostream>
using namespace std;

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n <= 2)
            return 1;
        int x = 0, y = 1, z = 1, sum = 0;
        int i = 3;
        while (i++ <= n)
        {
            sum = x + y + z;
            x = y;
            y = z;
            z = sum;
        }
        return sum;
    }
};

int main() {}