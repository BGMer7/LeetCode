#include <vector>
#include <stack>
#include <bitset>
#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> &pre) {
        vector<vector<int>> graph(n, vector<int>());
        vector<int> indegree(n);
        vector<int> res;

        for (auto p : pre) {
            graph[p[1]].push_back(p[0]); // graph[i]后面跟着的都是它的后序课程
            ++indegree[p[0]];
        }
        queue<int> q;
        for (int i(0); i < n; ++i)
            if (indegree[i] == 0) // 如果这个节点没有入度，那么就说明它是别的课程的前序，那么就从这些节点开始，要么这个节点就真的是isolation
                q.push(i);

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            res.push_back(p);

            for (auto e : graph[p])
                if (--indegree[e] == 0)
                    q.push(e);
        }
        return res.size() == n ? res : vector<int>();
    }
};

int main() {}