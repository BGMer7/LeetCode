#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        if (m * n != original.size())
            return vector<vector<int>>{};

        vector<vector<int>> res;
        /**
         * @brief
         *
        for (int i(0); i < original.size(); i += n)
        {
            vector<int> temp;
            temp.assign(original.begin() + i, original.begin() + i + n);
            res.push_back(temp);
        }
         */

        for (auto it = original.begin(); it != original.end(); it += n)
            res.emplace_back(it, it + n);
        return res;
    }
};

int main()
{
    Solution solution;
    return 0;
}