#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        int height = wall.size(), width = 0;
        unordered_map<int, int> m;
        vector<vector<int>> partition(height);
        for (int i(0); i < height; ++i)
        {
            width = 0;
            for (int &w : wall[i])
            {
                width += w;
                ++m[width];
            }
        }
        m.erase(width);
        int max_cnt = 0;
        for (const auto &[_, c] : m)
            max_cnt = max(max_cnt, c);

        return height - max_cnt;
    }
};

int main() {}