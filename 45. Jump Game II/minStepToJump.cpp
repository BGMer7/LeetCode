#include<vector>
#include<iostream>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int maxPos = 0, n = nums.size(), rightBorder = 0, step = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (maxPos >= i)
            {
                maxPos = max(maxPos, i + nums[i]);
                if (i == rightBorder) // 如果i已经遍历到了最远可以到达的地方
                {
                    rightBorder = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};

main(){
    vector<int> nums{2,3,1,1,4};
    Solution sol;
    cout << sol.jump(nums);
}