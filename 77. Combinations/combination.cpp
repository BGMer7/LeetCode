#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        dfs(n, k, 1);
        return Res;
    }
    vector<int> res;
    vector<vector<int>> Res;
    void dfs(int n, int k, int start)
    {
        if (res.size() == k)
        {
            Res.push_back(res);
            return;
        }
        for (int i = start; i <= n; i++)
        {
            res.push_back(i);
            dfs(n, k, i + 1);
            a
                res.pop_back();
        }
    }
};

int main()
{
}