#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int m, n;

public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<int> row, col;
        m = matrix.size();
        n = matrix[0].size();
        for (int i(0); i < m; ++i)
        {
            for (int j(0); j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }

        if (row.size() == 0 && col.size() == 0)
            return;

        vector<int> zeroRow(n, 0);
        for (int i(0); i < row.size(); ++i)
        {
            setRowZero(matrix, row[i]);
        }

        for (int i(0); i < col.size(); ++i)
        {
            setColZero(matrix, col[i]);
        }
        return;
    }

    void setColZero(vector<vector<int>> &matrix, int col)
    {
        for (int i(0); i < m; ++i)
            matrix[i][col] = 0;
    }

    void setRowZero(vector<vector<int>> &matrix, int row)
    {
        for (int i(0); i < n; ++i)
            matrix[row][i] = 0;
    }
};

int main() {}