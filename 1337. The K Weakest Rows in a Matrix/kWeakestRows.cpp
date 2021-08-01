#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        const int len = mat.size();
        vector<pair<int, int>> army;
        for (int i(0); i < len; ++i)
        {
            int sum = accumulate(mat[i].begin(), mat[i].end(), 0);
            army.push_back(make_pair(sum, i));
        }
        sort(army.begin(), army.end());

        vector<int> res;
        for (int i(0); i < k; ++i)
        {
            res.push_back(army[i].second);
        }
        return res;
    }
};

int main() {}