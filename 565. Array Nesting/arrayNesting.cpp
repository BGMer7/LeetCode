#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        int len = nums.size();
        int res = 0;
        vector<int> sign(len);
        for (int i = 0; i < nums.size(); ++i)
        {
            int start = nums[i], count = 0;
            if (sign[i] == 1)
                continue;
            do
            {
                start = nums[start];
                sign[start] = 1;
                count++;
            } while (start != nums[i]);
            res = max(res, count);
        }
        return res;
    }
};

int main() {}