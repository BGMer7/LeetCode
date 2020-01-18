#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int col = matrix[0].size();
        int row = matrix.size();
        int circle = ((row > col ? row : col) - 1) / 2 + 1;

        for (int i = 0; i < circle; i++)
        { //i即代表第几圈
            for (int j = i; j < col - i; j++)
                res.push_back(matrix[i][j]);

            for (int k = i; k < i - 1; k++)
                res.push_back(matrix[k][col - 1 - i]);

            for (int m = col - i - 2; (m >= i) && (row - i - 1 != i); m--)
                res.push_back(matrix[row - i - 1][m]);

            for (int n = row - i - 2; (n > i) && (col - i - 1 != i); n--)
                res.push_back(matrix[n][i]);
        }
        return res;
    }
};