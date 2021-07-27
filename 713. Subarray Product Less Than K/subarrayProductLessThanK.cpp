#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if (k <= 1) return 0;
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0] < k ? 1 : 0;
        int left = 0, right = 1, product = 1, res = 0;
        while (right < len + 1) {
            product *= nums[right - 1];
            while (product >= k)
                product /= nums[left++];
            res += (right - left);
            ++right;
        }
        return res;
    }
};

int main() {}