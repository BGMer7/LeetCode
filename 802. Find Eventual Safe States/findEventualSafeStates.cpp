#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        const int n = graph.size();
        vector<int> indegree(n);
        vector<vector<int>> rgraph(n); // 将有向图中的所有指向反向，原先的graph代表i->destination，rgraph中是destination->i
        for (int i(0); i < n; ++i)
        {
            for (int destination : graph[i])
                rgraph[destination].push_back(i);
            indegree[i] = graph[i].size(); // 这个点的出度还是由原graph决定
        }
        queue<int> q;

        for (int i(n - 1); i >= 0; --i)
            // 如果出度为0，那么说明这个节点是俺定义所规定的安全节点，从安全节点出发到达的点，一定也是安全的
            if (graph[i].size() == 0)
                q.push(i);

        while (!q.empty())
        {
            int head = q.front();
            q.pop();
            for (int destination : rgraph[head])
            {
                // 如果剔除了到达安全节点的安全路线之后，这个节点也没有了出度，那他也变成安全节点
                if (--indegree[destination] == 0)
                    q.push(destination);
            }
        }
        vector<int> res;
        for (int i(0); i < n; ++i)
            if (indegree[i] == 0)
                res.push_back(i);

        return res;
    }
};

class SolutionDFS
{
private:
    bool dfs(int i, vector<int> &color, vector<vector<int>> &graph)
    {
        if (color[i] > 0)         // 超过0的结果中，如果他已经是2了，那就是安全的
            return color[i] == 2; // 在递归遍历中，如果这个点是1，那么此时返回false
        color[i] = 1;
        for (int e : graph[i])
            if (!dfs(e, color, graph))
                return false; // 一旦这个节点有一个出度节点不满足，这个节点就不满足

        color[i] = 2; // 该节点满足
        return true;  // 返回true
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        const int n = graph.size();
        vector<int> color(n);
        vector<int> res;
        for (int i(0); i < n; ++i)
            if (dfs(i, color, graph))
                res.push_back(i);

        return res;
    }
};

int main()
{
}