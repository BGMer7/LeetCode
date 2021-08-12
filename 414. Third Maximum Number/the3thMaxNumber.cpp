#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        const int len = nums.size();
        long long _max = -2147483649, _mid = -2147483649, _min = -2147483649;
        for (int i(0); i < len; ++i)
        {
            if ((nums[i] == _max) || (nums[i] == _mid) || (nums[i] == _min))
                continue;

            if (nums[i] > _max)
            {
                _min = _mid;
                _mid = _max;
                _max = nums[i];
            }
            else if (nums[i] > _mid)
            {
                _min = _mid;
                _mid = nums[i];
            }
            else if (nums[i] > _min)
            {
                _min = nums[i];
            }
        }
        return _min == -2147483649 ? _max : _min;
    }
};

int main() {}