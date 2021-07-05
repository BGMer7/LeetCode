#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (int i(0); i < intervals.size(); i++)
        {
            int left = intervals[i][0], right = intervals[i][1];
            if (res.empty() || res.back()[1] < left)
                res.push_back({left, right});
            else
                res.back()[1] = max(right, res.back()[1]);
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> nums;
    nums.push_back({1, 2});
    nums.push_back({3, 4});
    nums.push_back({5, 6});

    // vector<vector<int>>::iterator it;
    // cout << it[0];
    // 二维容器的迭代器，一个迭代器创建出来之后还需要再创建一个迭代器，两个迭代器才能遍历
}