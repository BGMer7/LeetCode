#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    int m, n;
    vector<pair<int, int>> o;
    vector<pair<int, int>> s;

    void solve(vector<vector<char>> &board)
    {
        m = board.size();
        n = board[0].size();
        int i = 0;
        int j = 0;

        while (j < n)
        {
            if (board[i][j] == 'O')
                o.push_back({i, j});
            ++j;
        }
        --j;
        while (i < m)
        {
            if (board[i][j] == 'O')
                o.push_back({i, j});
            ++i;
        }
        --i;
        while (j >= 0)
        {
            if (board[i][j] == 'O')
                o.push_back({i, j});
            --j;
        }
        ++j;
        while (i >= 0)
        {
            if (board[i][j] == 'O')
                o.push_back({i, j});
            --i;
        }
        for (auto p : o)
        {
            int r = p.first;
            int c = p.second;
            dfs(board, r, c);
        }
        cout << s.size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                board[i][j] = 'X';
            }
        }

        // for(auto o:s)
        // {
        //     board[o.first][o.second] = 'O';
        // }
    }

    void dfs(vector<vector<char>> &board, int r, int c)
    {
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] == 'X' || board[r][c] == '.')
            return;
        s.push_back({r, c});
        board[r][c] = '.';
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }
};

int main()
{
    vector<vector<char>> board{{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    Solution sol;
    sol.solve(board);
}