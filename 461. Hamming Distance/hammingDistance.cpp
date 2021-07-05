#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int diff = x ^ y, res = 0;
        while (diff)
        {
            res += diff & 1;
            diff >>= 1;
        }
        return res;
    }
};

int main()
{
    int x = 5, y = 10;
    int diff = x ^ y;
    cout << diff;
}