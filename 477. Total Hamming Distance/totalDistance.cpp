#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
        
    }

    int hammingDistance(int x, int y)
    {
        int diff = x ^ y, res;
        while (diff)
        {
            res += diff & 1;
            diff >>= 1;
        }
        return res;
    }
};