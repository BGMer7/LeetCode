#include <vector>
#include <unordered_map>
#include <math.h>
#include <random>

using namespace std;

class Solution
{
private:
    unordered_map<int, int> mp;
    int m, n;
    int k;

public:
    Solution(int m, int n)
    {
        this->m = m;
        this->n = n;
        this->k = m * n; // 二维数组转一维
    }

    vector<int> flip()
    {
        int key = rand() % k;
        int val = key;

        --k; // 折叠一次，就会少一个0

        if (mp.count(key))
        {
            val = mp[key];
        }
        if (mp.count(k))
        {
            mp[key] = mp[k];
        }
        else
        {
            mp[key] = k;
        }
        return {val / n, val % n};
    }

    void reset()
    {
        k = m * n;
        mp.clear();
    }
};

int main() {}