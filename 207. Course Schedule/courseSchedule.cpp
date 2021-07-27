#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &pre)
    {
        vector<int> res;
        vector<vector<int>> graph(n, vector<int>());
        vector<int> indegree(n);
        
        for(auto p: pre) {
            ++indegree[p[0]];
            graph[p[1]].push_back(p[0]);
        }

        queue<int> q;
        for(int i(0); i<n; ++i) 
            if(indegree[i]==0) 
                q.push(i);
        
        while(!q.empty()) {
            auto i = q.front();
            q.pop();
            res.push_back(i);

            for(auto postCourse: graph[i]) {
                if(--indegree[postCourse]==0)
                    q.push(postCourse);
            }
        }

        return res.size()==n?true:false;
    }
};

int main() {}