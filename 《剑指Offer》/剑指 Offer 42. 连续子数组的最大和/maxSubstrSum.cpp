#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int res = nums[0];
        for (int i(1); i < n; ++i)
        {
            if (nums[i - 1] > 0)
                nums[i] = nums[i - 1] + nums[i]; // 正收益
            res = max(res, nums[i]);
        }
        return res;
    }
};

int main() {}