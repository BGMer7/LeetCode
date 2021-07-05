#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int red = 0, white = 0, blue = 0;
        for (auto num : nums)
        {
            if (num == 0)
                red++;
            if (num == 1)
                white++;
            if (num == 2)
                blue++;
        }
        nums.clear();
        for (int i(0); i < red; ++i)
            nums.push_back(0);
        for (int i(0); i < white; ++i)
            nums.push_back(1);
        for (int i(0); i < blue; ++i)
            nums.push_back(2);
    }
};

int main(){
    vector<int> nums{0,0,2,1,2,1,1,1,0,2,1};
    Solution sol;
    sol.sortColors(nums);
}