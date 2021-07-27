#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int depth = triangle.size();
        vector<int> level(depth);
        level[0] = triangle[0][0];
        for (int i(1); i < depth; ++i)
        {
            level[i] = level[i - 1] + triangle[i][i];
            for (int j = i - 1; j > 0; --j)
            {
                level[j] = min(level[j - 1], level[j]) + triangle[i][j];
            }
            level[0] += triangle[i][0];
        }
        return *min_element(level.begin(), level.end());
    }
};

int main() {}