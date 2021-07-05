#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, bool> m;
        for(auto num: nums) {
            if(m[num] == false)
                m[num]=true;
            else if(m[num] == true)
                return false;
        }
        return true;
    }
};