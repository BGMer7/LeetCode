#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    // 曼哈顿距离，即各坐标轴之差的绝对值之和。两点之间的最短直线画出来的距离是欧式距离
    int manhattanDistance(vector<int> &a, vector<int> &b)
    {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target)
    {
        vector<int> origin{0, 0};
        int originManhattanDistance = manhattanDistance(origin, target);
        for (auto &ghost : ghosts)
        {
            // 如果ghost的曼哈顿距离比初始点还要短，那么就能等着origin等他来
            if (manhattanDistance(ghost, target) <= originManhattanDistance)
                return false;
        }
        return true;
    }
};

int main() {}