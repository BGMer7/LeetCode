#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<int> stk{0};
    vector<vector<int>> res;

    void dfs(vector<vector<int>> &graph, int src, int dst)
    {
        if (src == dst)
        {
            res.push_back(stk);
            return;
        }

        for (auto next : graph[src])
        {
            stk.push_back(next);
            dfs(graph, next, dst);
            stk.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        const int n = graph.size();
        dfs(graph, 0, n - 1);
        return res;
    }
};

int main() {}