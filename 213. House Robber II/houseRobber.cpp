#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    void print(vector<int> &nums) {
        for(auto num: nums)
            cout << num << " ";
        cout << endl;
    }

public:
    int rob(vector<int> &nums)
    {
        int size = nums.size();
        if(size==0) return -1;
        else if(size==1) return nums[0];
        else if(size==2) return max(nums[0], nums[1]);
        nums.push_back(nums[0]);
        vector<int> dp(size+1, 0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i(2); i<size+1; ++i) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        print(dp);
        return dp[size]-nums[0];

    }
};

int main(){
    vector<int> nums{1,2,1,1};
    int res;
    Solution sol;
    res=sol.rob(nums);


}