#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    // bool canJump(vector<int> &nums)
    // // 动态规划的思想，构建一个vector，里面存放nums的每个数组能不能到达的bool值，但是时间内存都消耗很大
    // {
    //     int n = nums.size();
    //     vector<bool> canJump(n, false);
    //     canJump[0] = true;
    //     for (int i(0); i < nums.size(); i++)
    //     {
    //         if (canJump[i] == false)
    //             return false;
    //         int k = nums[i], pos = i;
    //         while (k--)
    //         {
    //             if (pos + 1 >= n)
    //                 return true;
    //             canJump[++pos] = true;
    //         }
    //     }
    //     return nums[n-1];
    // }

    bool canJump(vector<int> &nums){
        int n = nums.size();
        int pos=0;
        for(int i(0);i<n;++i){
            if(i>pos) return false;
            pos = max(pos, pos+nums[i]);
        }
        return true;
    }
};

main(){
    vector<int> nums { 2, 3, 1, 1, 4 };
    Solution sol;
    cout << sol.canJump(nums);

}