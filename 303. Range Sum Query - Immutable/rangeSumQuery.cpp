#include <vector>
using namespace std;

class NumArray
{
private:
    vector<int> prefixSum;


public:
    NumArray(vector<int> &nums)
    {
        int n=nums.size();
        prefixSum.resize(n+1);
        int sum=0;
        for(int i(0); i<n; ++i) {
            sum += nums[i];
            prefixSum[i+1] = sum;
        }
    }

    int sumRange(int left, int right)
    {
        return prefixSum[right+1] - prefixSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {}