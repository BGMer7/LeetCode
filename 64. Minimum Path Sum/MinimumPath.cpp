#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int row = grid.size();
        if (row == 0)
            return 0;
        int col = grid[0].size();
        if (col == 0)
            return 0;
        for (int i = 1; i < col; i++)
        {
            grid[0][i] += grid[0][i - 1];
        }
        for (int i = 1; i < row; i++)
        {
            grid[i][0] += grid[i - 1][0];
        }
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[row - 1][col - 1];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> nums{
        {1, 2, 5},
        {3, 2, 1}};
    int res;
    res = s.minPathSum(nums);
    cout << res;
}