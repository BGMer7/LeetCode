#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> res;
        for (int n : nums2)
            if (s.erase(n))
                res.push_back(n); //erase既判断了n是否存在,又删除了set中的元素避免重复
        return res;
    }
};

int main(){
    vector<int> nums1{1,2,3,4,4,5};
    vector<int> nums2{1,2,3,4,5,6};
    Solution sol;
    sol.intersection(nums1, nums2);

}