#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if(n==1)
            return nums[0];

        int left = 0, right = n-1, mid = left+(right-left)/2;
        while(left<right){
            mid = left+(right-left)/2;
            if(nums[mid]<nums[right])
                right = mid;
            else
                left=mid+1;
        }
        return nums[left];
    }
};

int main(){
    vector<int> nums{5,6,7,8,9,1,2,3,4};
    Solution sol;
    cout << sol.findMin(nums);
}