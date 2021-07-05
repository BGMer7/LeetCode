#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution
// DFS找出第一个岛屿的全部点，BFS开始让第一个岛不断向外扩张
{
public:
    int m, n; // 定义两个全局变量，用来记录数组size

    int shortestBridge(vector<vector<int>> &A)
    {
        queue<pair<int, int>> q;
        auto res = dfsFind(A);
        dfsDye(A, res.first, res.second, q); // 将返回的初始岛屿坐标为起点对第一个岛屿进行染色
        printvec(A);
        return bfsConnect(A, q);
    }

    pair<int, int> dfsFind(vector<vector<int>> &nums)
    {
        m = nums.size();
        n = nums[0].size();
        for (int i(0); i < m; ++i)
        {
            for (int j(0); j < n; ++j)
            {
                if (nums[i][j]) // 只需要找到第一个不为零的点，就当作第一个岛屿的起点，将坐标返回
                    return {i, j};
            }
        }
        return {-1, -1}; // 如果没有找到就返回{-1,-1}，但是已知题目一定有解
    }

    void dfsDye(vector<vector<int>> &nums, int r, int c, queue<pair<int, int>> &q) // DFS染色
    {
        if (r < 0 || r >= m || c < 0 || c >= n || nums[r][c] != 1) // 已经超出第一个岛屿的陆地范围
            return;

        nums[r][c] = 2; // 将第一个岛屿染色为2
        q.push({r, c});
        dfsDye(nums, r, c + 1, q);
        dfsDye(nums, r, c - 1, q);
        dfsDye(nums, r + 1, c, q);
        dfsDye(nums, r - 1, c, q);
    }

    int bfsConnect(vector<vector<int>> &nums, queue<pair<int, int>> &q)
    {
        vector<pair<int, int>> direction{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 四个方向
        int bridge = 0;                                                     // 先初始化桥的长度为0
        while (!q.empty())
        {
            for (int k(q.size() - 1); k >= 0; --k)
            {
                auto cur = q.front();
                q.pop();
                int &r = cur.first;
                int &c = cur.second;
                for (int i(0); i < 4; ++i)
                {
                    int x = r + direction[i].first;
                    int y = c + direction[i].second;
                    if (x < 0 || x >= m || y < 0 || y >= n || nums[x][y] == 2 || nums[x][y] == 3)
                    // 标注为2的，是一号岛屿，标注为3的，是遍历过的海面
                        continue;
                    if (nums[x][y] == 1) // 如果等于1，表面接触到了第二个岛屿
                        return bridge;
                    nums[x][y] = 3; // 不为1不为2不为3，那就是海面，将海面标记为3之后压入队列等待下次遍历
                    q.push({x, y});
                }
            }
            bridge++;
        }
        return -1;
    }

private:
    void printvec(vector<vector<int>> nums)
    {
        for (auto n : nums)
        {
            for (auto k : n)
                cout << k << " ";
            cout << endl;
        }
    }
};

int main()
{
    vector<vector<int>> nums{{0, 1, 0}, {0, 0, 0}, {0, 0, 1}};
    Solution sol;
    int res = sol.shortestBridge(nums);
    cout << res;
}