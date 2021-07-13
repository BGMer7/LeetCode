#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> sum_index;
        sum_index[0]=-1;
        int count = 0, len = 0;
        for(int i(0); i<nums.size(); ++i) {
            if(nums[i]==0) 
                --count;
            else if(nums[i]==1)
                ++count;
            
            if(sum_index.find(count)!=sum_index.end())
                len=max(i-sum_index[count], len);
            else 
                sum_index[count] = i;
        }
        return len;
    }
};

int main() {
    vector<int> nums { 0,1,1,1,1,1,1,1,1,1};
    Solution sol;
    cout << sol.findMaxLength(nums);
}