#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>

using namespace std;

class Solution
{
public:
    // int singleNumber(vector<int> &nums)
    // {
    //     set<int> s;
    //     for(auto n:nums){
    //         if(s.find(n)==s.end())
    //             s.insert(n);
    //         else
    //             s.erase(n);
    //     }
    //     return *s.begin();
    // }

    int singleNumber(vector<int> &nums) // bit manipulation
    {
        int carry = 0;
        for(int n:nums){
            carry^=n;
        }
        return carry;
    }
};

int main(){
    vector<int> nums{1,1,2,2,3,3,5};
    Solution sol;
    cout << sol.singleNumber(nums);
}