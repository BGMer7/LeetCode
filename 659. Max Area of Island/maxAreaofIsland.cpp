#include <vector>
#include <stack>

using namespace std;

class TwoFuncSolution1 // 主函数辅函数法 // 递归
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) // main function
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int max_area = 0;
        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[0].size(); c++)
            {
                max_area = max(max_area, dfs(grid, r, c));
            }
        }
        return max_area;
    }

    int dfs(vector<vector<int>> &grid, int r, int c)
    {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0)
            return 0;

        grid[r][c] = 0;
        return 1 + dfs(grid, r + 1, c) + dfs(grid, r - 1, c) + dfs(grid, r, c + 1) + dfs(grid, r, c - 1);
    }
};

class TwoFuncSolution2
{
private:
    vector<int> directions{-1, 0, 1, 0, -1};

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    max_area = max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }

    int dfs(vector<vector<int>> &grid, int r, int c)
    {
        if (grid[r][c] == 0)
            return 0;

        grid[r][c] = 0;
        int x, y, area = 0;
        for (int i = 0; i < 4; i++)
        {
            x = r + directions[i];
            y = c + directions[i + 1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
                area = area + dfs(grid, x, y);
        }
        return area;
    }
};

class StackSolution
{
private:
    vector<int> directions{-1, 0, 1, 0, -1};

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        int x, y, local_area, area = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j])
                {
                    local_area = 1;
                    grid[i][j] = 0;
                    stack<pair<int, int>> island;
                    island.push({i, j});
                    while (!island.empty())
                    {
                        //auto [r, c] = island.top();
                        int r = island.top().first;
                        int c = island.top().second;
                        island.pop();
                        for (int d = 0; d < 4; ++d)
                        {
                            x = r + directions[d];
                            y = c + directions[d];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
                            {
                                grid[x][y] = 0;
                                ++local_area;
                                island.push({x, y});
                            }
                        }
                    }
                    area = max(local_area, area);
                }
            }
        }
        return area;
    }
};

class CountIsland // 找出一共有多少个岛屿
{
private:
    vector<int> directions{-1, 0, 1, 0, -1};

public:
    int findIslandNum(vector<vector<int>> &islands)
    {
        int m = islands.size(), n = islands[0].size(), count = 0;
        int x, y;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (islands[i][j])
                {
                    islands[i][j] = 0;

                    stack<pair<int, int>> islandstack;
                    islandstack.push({i, j});
                    while (!islandstack.empty())
                    {
                        int r = islandstack.top().first;
                        int c = islandstack.top().second;
                        islandstack.pop();
                        for (int k = 0; k < 4; ++k)
                        {
                            x = r + directions[k];
                            y = c + directions[k + 1];
                            if (x >= 0 && x < m && y >= 0 && y < n && islands[x][y] == 1)
                            {
                                islands[x][y] = 0;
                                islandstack.push({x, y});
                            }
                        }
                    }
                    ++count;
                }
            }
        }
        return count;
    }
};

int main()
{
}