#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> frequency(n);
        vector<int> res;
        for (auto c : nums)
        {
            frequency[c - 1]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (frequency[i] == 0)
                res.push_back(i + 1);
        }
        return res;
    }
};

int main()
{
    return 0;
}