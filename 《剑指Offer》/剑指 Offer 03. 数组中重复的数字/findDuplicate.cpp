#include <vector>
#include <iostream>
#include <set>
using namespace std;

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        set<int> s;
        for (auto num : nums)
        {
            if (s.count(num) == 1)
                return num;
            else
                s.insert(num);
        }
        return -1;
    }
};

class SolutionVector
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> isVisited(n, false);
        for (auto num : nums)
        {
            if (isVisited[num])
                return num;
            else
                isVisited[num] = true;
        }
        return -1;
    }
};

int main() {}