#include <vector>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        const int size = grid.size();
        vector<int> maxInRow(size); // 该数组记录横向最大值
        vector<int> maxInCol(size); // 该数组记录竖向最大值
        for (int i(0); i<size; ++i) {
            for (int j(0); j<size; ++j) {
                maxInRow[i] = max(maxInRow[i], grid[i][j]);
                maxInCol[j] = max(maxInCol[j], grid[i][j]);
                // 不停比较，用当前遍历的那个值不断和数组中存储的最大值比较，每次更新最大值
                // 一个是i一个是j表示一个是行最大值，一个是列最大值
            }
        }
       
        int res=0;
        for (int i(0); i<size; ++i) {
            for (int j(0); j<size; ++j) {
                res += (min(maxInRow[i], maxInCol[j]) - grid[i][j]); // 累加
            }
        }
        return res;

    }
};

int main() {}

