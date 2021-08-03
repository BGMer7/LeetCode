#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto const &time : times)
            graph[time[0]].push_back({time[2], time[1]});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        q.emplace(0, k);
        while (!q.empty())
        {
            auto p = q.top();
            q.pop();
            const int v = p.second; // the v value here represents the destination node, particularly, the {0, k} is a exception, it just means a start.
            for (auto destination : graph[v])
            {
                int path = dist[v] + destination.first;
                if (path < dist[destination.second])
                {
                    dist[destination.second] = path;
                    q.emplace(path, destination.second);
                }
            }
        }

        int max_time = INT_MIN;

        for (int i = 1; i < dist.size(); ++i)
            if (max_time < dist[i])
                max_time = dist[i];

        return max_time == INT_MAX ? -1 : max_time;
    }
};
int main() {}