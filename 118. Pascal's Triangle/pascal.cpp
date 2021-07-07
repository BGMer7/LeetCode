#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++)
            res.push_back(vector<int>(i + 1, 1));

        for (int i = 0; i < numRows; i++)
            for (int j = 1; j < i; j++)
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        return res;
    }
};

class Solution0707
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        if (numRows == 0)
            return res;
        if (numRows == 1)
        {
            res.push_back({1});
            return res;
        }
        if (numRows == 2)
        {
            res.push_back({1});
            res.push_back({1, 1});
            return res;
        }
        res.push_back({1});
        res.push_back({1, 1});
        for (int i(3); i <= numRows; ++i)
        {
            vector<int> level(i, 1);
            for (int j(1); j < i - 1; ++j)
            {
                level[j] = res.back()[j - 1] + res.back()[j];
            }
            res.push_back(level);
        }
        return res;
    }
};

int main()
{
}