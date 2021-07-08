#include <vector>
#include <iostream>
#include <set>
using namespace std;

class SolutionBacktracking // DFS加剪枝回溯的方法虽然可以，但是在大量重复样本的情况下会超时
{
protected:
    vector<string> res;
    set<string> s;
    int col, row;

    void dfs(vector<vector<char>> &board, string word, int index, int i, int j)
    {
        if (i < 0 || j < 0 || i >= row || j >= col || board[i][j] != word[index] || board[i][j] == '.')
            return;

        if (index == word.size() - 1)
        {
            s.insert(word);
            return;
        }

        char tmp = board[i][j];
        board[i][j] = '.';
        dfs(board, word, index + 1, i - 1, j);
        dfs(board, word, index + 1, i + 1, j);
        dfs(board, word, index + 1, i, j - 1);
        dfs(board, word, index + 1, i, j + 1);
        board[i][j] = tmp;
    }

    void find(vector<vector<char>> &board, string word)
    {
        for (int i(0); i < row; ++i)
            for (int j(0); j < col; ++j)
                if (board[i][j] == word[0])
                    dfs(board, word, 0, i, j);
                else
                    continue;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        row = board.size();
        col = board[0].size();
        for (string word : words)
            find(board, word);

        res.assign(s.begin(), s.end());
        return res;
    }
};

class TrieNode // 构造一个Trie树
{
public:
    string word = "";
    vector<TrieNode *> nodes;
    TrieNode() : nodes(26, 0) {}
    ~TrieNode()
    {
        for (const auto &node : nodes)
            delete node;
    }
};

class Solution
{
private:
    vector<string> res;
    int row, col;

    void dfs(vector<vector<char>> &board, TrieNode *root, int i, int j)
    {
        if (i < 0 || j < 0 || i >= row || j >= col)
            return;
        char tmp = board[i][j];
        if (board[i][j] == '.' || root->nodes[tmp - 'a'] == 0)
            return;
        board[i][j] = '.';
        root = root->nodes[tmp - 'a'];
        if (root->word != "")
        {
            res.push_back(root->word);
            root->word = "";
        }
        dfs(board, root, i + 1, j);
        dfs(board, root, i - 1, j);
        dfs(board, root, i, j + 1);
        dfs(board, root, i, j - 1);
        board[i][j] = tmp;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        row = board.size();
        col = board[0].size();
        if (!row || !col)
            return res;

        TrieNode *root = new TrieNode(); // 创建一个字典树节点

        for (string word : words)
        {
            TrieNode *cur = root;
            for (int i(0); i < word.size(); ++i)
            {
                int index = word[i] - 'a';
                if (!cur->nodes[index])
                    cur->nodes[index] = new TrieNode();
                cur = cur->nodes[index];
            }
            cur->word = word;
        }
        for (int i(0); i < row; ++i)
            for (int j(0); j < col; ++j)
                dfs(board, root, i, j);

        //delete root;
        return res;
    }
};

int main()
{
    vector<vector<char>> board = {
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
    };
    Solution sol;
    vector<string> wordList{"a", "aa", "aaa", "aaaa"};
    vector<string> res = sol.findWords(board, wordList);
    cout << res.size() << endl;
}
/*
 #######  ##    ## ########    ##     ##  #######  ########  ########    ######## #### ##     ## ########    #### 
##     ## ###   ## ##          ###   ### ##     ## ##     ## ##             ##     ##  ###   ### ##          #### 
##     ## ####  ## ##          #### #### ##     ## ##     ## ##             ##     ##  #### #### ##          #### 
##     ## ## ## ## ######      ## ### ## ##     ## ########  ######         ##     ##  ## ### ## ######       ##  
##     ## ##  #### ##          ##     ## ##     ## ##   ##   ##             ##     ##  ##     ## ##               
##     ## ##   ### ##          ##     ## ##     ## ##    ##  ##             ##     ##  ##     ## ##          #### 
 #######  ##    ## ########    ##     ##  #######  ##     ## ########       ##    #### ##     ## ########    #### 
*/


 