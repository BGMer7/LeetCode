#include <vector>
#include <queue>
using namespace std;
// 状态
struct State
{
    int cover;
    int i;
    State(int _cover, int _i) : cover(_cover), i(_i) {}
};

class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &adj)
    {
        const int N = adj.size();
        const int END = (1 << N) - 1;
        vector<State> currs;
        vector<vector<int>> dist(1 << N, vector<int>(N, 0)); // 标记是否已遍历

        // 从所有点（同时）出发BFS
        for (int i = 0; i < N; ++i)
        {
            currs.push_back(State(1 << i, i));
            dist[1 << i][i] = 0;
        }

        // 层次遍历
        for (int level = 0; !currs.empty(); ++level)
        {
            vector<State> nexts;
            for (auto curr : currs)
            {
                for (int j : adj[curr.i])
                {
                    int v = curr.cover | (1 << j);
                    if (v == END)
                        return level + 1; // 终点
                    if (!dist[v][j])
                    {
                        dist[v][j] = 1;
                        nexts.push_back(State(v, j));
                    }
                }
            }
            currs = nexts;
        }
        return 0;
    }
};
int main() {}