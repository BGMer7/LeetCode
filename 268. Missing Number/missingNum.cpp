#include <vector>
#include <iostream>
using namespace std;


class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        int realSum = 0;
        for (int n : nums)
        {
            realSum += n;
        }
        return sum - realSum;
    }
};

main(){
    vector<int> nums{0,2,3};
    Solution sol;
    cout << sol.missingNumber(nums);

}