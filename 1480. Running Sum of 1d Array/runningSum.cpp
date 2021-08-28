#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        int sum = 0;
        vector<int> res;
        for (int i(0); i < nums.size(); ++i)
        {
            res.push_back(sum += nums[i]);
        }
        return res;
    }
};

int main() {}