#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> res;

public:
    vector<int> lexicalOrder(int n)
    {
        for (int i(1); i < 10; ++i)
            dfs(i,n);
        return res;
    }

    void dfs(int num, int n)
    {
        if (num > n)
            return;

        cout << num << endl;
        res.push_back(num);
        for (int i(0); i < 10; ++i)
            dfs(10 * num + i, n);
    }
};

int main()
{
    Solution sol;
    sol.lexicalOrder(30);
}