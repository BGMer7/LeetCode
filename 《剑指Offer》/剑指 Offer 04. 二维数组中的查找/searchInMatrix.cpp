#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
            return false;

        int i = 0, j = matrix[0].size() - 1; // 从右上角开始遍历查找
        while (i < matrix.size() && j >= 0)
        {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                --j;
            else if (matrix[i][j] < target)
                ++i;
        }
        return false;
    }
};

int main() {}