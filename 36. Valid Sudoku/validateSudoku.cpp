#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> col(9, vector<int>(9, 0));
        vector<vector<int>> box(9, vector<int>(9, 0));
        cout << row[0].size() << endl;
        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] == '.')
                    continue;
                else
                {
                    int num = board[r][c] - '0';
                    if (row[r][num] == 1)
                        return false;
                    if (col[c][num] == 1)
                        return false;
                    if (box[r / 3 * 3 + c / 3][num] == 1)
                        return false;

                    row[r][num] = 1;
                    col[c][num] = 1;
                    box[r / 3 * 3 + c / 3][num] = 1;
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<int>> box(9, vector<int>(9, 0));
    cout << box[0][0] << endl;
    int a = 5;
    int b = 3;
    int c = a / b;
    cout << c;
}