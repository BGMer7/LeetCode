#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int direct[5] = {-1, 0, 1, 0, -1};

    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, string word, int i, int j, int index)
    {
        if (board[i][j] != word[index] || i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;

        if (index == word.size() - 1)
            return true;

        board[i][j] = '.';
        // if (i >= 0 && j >= 0 && i < board.size() && j < board[0].size() && board[i][j] == word[index])
        if (dfs(board, word, i + 1, j, index + 1) || dfs(board, word, i, j + 1, index + 1) || dfs(board, word, i - 1, j, index + 1) || dfs(board, word, i, j - 1, index + 1))
        {
            cout << "i:" << i << " j:" << j << endl;
            return true;
        }
        board[i][j] = word[index];
        return false;
    }
};

int main()
{
    vector<vector<char>> board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word("ABCCDE");
    Solution sol;
    bool res;
    res = sol.exist(board, word);
}
