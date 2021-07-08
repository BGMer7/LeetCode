#include <vector>
#include <iostream>

using namespace std;

class Solution
{
protected:
    int row, col;
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == '0')
            return;
        else if (grid[i][j] == '1')
            grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        row = grid.size();
        col = grid[0].size();
        int cnt = 0;
        for (int i(0); i < row; ++i)
        {
            for (int j(0); j < col; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++cnt;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};

int main() {}