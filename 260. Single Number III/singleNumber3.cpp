#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int sum = 0;
        for (int n : nums)
            sum ^= n;

        int i = 1;
        while (!(sum & i))
            i <<= 1;

        int a = 1, b = 1;
        for (int n : nums)
        {
            if (n & i)
                a ^= n;
            else 
                b ^= n;
        }
        return {a, b};
    }
};

int main() {
    vector<int> nums{1,2,1,2,3,4};
    Solution sol;
    
}