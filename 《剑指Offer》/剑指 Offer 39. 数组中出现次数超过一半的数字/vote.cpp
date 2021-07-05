#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int major, cnt = 0;
        for (int i(0); i < nums.size(); i++)
        {
            if (cnt == 0)
                major = nums[i];
            if (nums[i] == major)
                cnt++;
            else
                cnt--;
        }
        return major;
    }
};

int main() {}