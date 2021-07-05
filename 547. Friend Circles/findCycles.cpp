#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution
{
private:
    vector<int> directions{-1, 0, 1, 0, -1};

public:
    int findCycleNum(vector<vector<int>> &friends)
    {
        int m = friends.size(), count = 0;
        vector<bool> isFriend(m, false);
        for (int i = 0; i < m; ++i)
        {
            if (!isFriend[i])
            {
                ++count;
                isFriend[i] = true;
                stack<int> friendPool;
                friendPool.push(i);
                while (!friendPool.empty())
                {
                    int f = friendPool.top();
                    friendPool.pop();
                    for (int j = 0; j < m; ++j)
                    {
                        if (friends[f][j] && isFriend[j] == false)
                        {
                            isFriend[j] = true;
                            friendPool.push(j);
                        }
                    }
                }
            }
        }

        return count;
    }
};

class TwoFuncSolution
{
public:
    int findFriendsNum(vector<vector<int>> &friends)
    {
        int n = friends.size();
        int count = 0;
        vector<bool> isVisited(n, false);
        for (int i = 0; i < n; ++i)
        {
            if (!isVisited[i])
            {
                count++;
                dfs(friends, isVisited, n, i);
            }
        }
        return count;
    }

    void dfs(vector<vector<int>> &friends, vector<bool> &isVisited, int n, int i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (friends[i][j] == 1 && isVisited[j] == false)
            {
                isVisited[j] = true;
                dfs(friends, isVisited, n, j);
            }
        }
    }
};

int main()
{
    vector<vector<int>> friends{{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    Solution sol;
    int res = sol.findCycleNum(friends);
    TwoFuncSolution twoSol;
    int ans = twoSol.findFriendsNum(friends);
    cout << ans;

}