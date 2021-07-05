#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int row, col;
    string s;
    bool isFind = false;

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty())
            return false;
        s = word;
        row = board.size();
        col = board[0].size();
        vector<vector<bool>> isVisited(row, vector<bool>(col, false));
        for (int i(0); i < row; ++i)
            for (int j(0); j < col; ++j)
            {
                if (isFind)
                    return true;
                else
                    dfs(board, i, j, isVisited, 0);
            }
    }

    void dfs(vector<vector<char>> &board, int i, int j, vector<vector<bool>> &isVisited, int pos)
    {
        if (i < 0 || i >= row || j < 0 || j >= col)
            return;

        if (isVisited[i][j] == true || s[pos] != board[i][j])
            return;

        if (pos == s.size() - 1)
        {
            isFind = true;
            return;
        }

        isVisited[i][j] = true;
        dfs(board, i + 1, j, isVisited, pos + 1);
        dfs(board, i, j + 1, isVisited, pos + 1);
        dfs(board, i - 1, j, isVisited, pos + 1);
        dfs(board, i, j - 1, isVisited, pos + 1);
        isVisited[i][j] = false;
    }
};

class SolutionNoExtraSpace
{
private:
    int row, col;
    string s;
    bool isFind = false;

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty())
            return false;
        s = word;
        row = board.size();
        col = board[0].size();
        for (int i(0); i < row; ++i)
            for (int j(0); j < col; ++j)
            {
                if (isFind)
                    return true;
                else
                    dfs(board, i, j, 0);
            }
        return isFind;
    }

    void dfs(vector<vector<char>> &board, int i, int j, int pos)
    {
        if (i < 0 || i >= row || j < 0 || j >= col || s[pos] != board[i][j])
            return;

        if (pos == s.size() - 1)
        {
            isFind = true;
            return;
        }

        char tmp = board[i][j];
        board[i][j] = '\0';
        dfs(board, i + 1, j, pos + 1);
        dfs(board, i, j + 1, pos + 1);
        dfs(board, i - 1, j, pos + 1);
        dfs(board, i, j - 1, pos + 1);
        board[i][j] = tmp;
    }
};

int main() {}