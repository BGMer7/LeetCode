#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1, k = 0; k < j; j--) {
                while (k < j && nums[k] + nums[j] <= nums[i])
                    k++;
                res += j - k;
            }
        }
        return res;
    }
};

int main() {

}