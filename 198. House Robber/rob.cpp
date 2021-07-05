#include <vector>
#include <math.h>
#include <stdlib.h>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        int prev0 = nums[0], prev1 = max(nums[0], nums[1]), sum = 0;
        for (int i(2); i < n; ++i)
        {
            sum = max(nums[i] + prev0, prev1);
            prev0 = prev1;
            prev1 = sum;
        }
        return sum;
    }
};

int main()
{

}