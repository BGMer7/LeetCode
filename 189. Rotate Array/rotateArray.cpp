#include <vector>
#include <iostream>
using namespace std;

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int sz = nums.size();
//         k%=sz;
//         if(k==0) return;
//         vector<int>::iterator it = nums.begin()+(sz-k);
//         vector<int> back;
//         back.assign(it, nums.end());
//         nums.insert(nums.begin(), back.begin(), back.end());
//         nums.resize(sz);
//     }
// };

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int sz = nums.size();
        k %= sz;
        if (k == 0)
            return;
        int *p = &nums[0];
        cout << p << endl;
        vector<int>::iterator it = nums.begin() + (sz - k);
        nums.insert(nums.begin(), it, nums.end());
        nums.resize(sz);
    }
};

int main()
{
    vector<int> nums{1, 2, 3};
    Solution sol;
    sol.rotate(nums, 1);
    cout << nums[0] << endl;

    vector<int> a{1, 2, 3};
    cout << "max_size():" << a.max_size() << endl;
    cout << "size():" << a.size() << endl;
    cout << "capacity():" << a.capacity() << endl;
    cout << "---" << endl;

    int sdsd=10, sdfs= 1;
    a.reserve(sdsd+sdfs);
    cout << "size():" << a.size() << endl;
    cout << "capacity():" << a.capacity() << endl;
    cout << "---" << endl;

    vector<int> b;

    for(int i(1); i<=20; ++i) {
        b.push_back(i);
        cout << "size():" << b.size() << endl;
        cout << "capacity():" << b.capacity() << endl;
        cout << "---" << endl;
    }
    
}