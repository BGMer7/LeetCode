#include <iostream>
#include <set>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        bool res = true;
        set<int> s;
        int trans = resolve(n);
        if (trans == 1)
            return true;
        while (s.count(trans) == 0)
        {
            s.insert(trans);
            trans = resolve(trans);
            if (trans == 1)
                return true;
        }
        return false;
    }

    int resolve(int n)
    {
        int sum = 0;
        while (n)
        {
            int decade = n % 10;
            sum += (decade * decade);
            n /= 10;
        }
        return sum;
    }
};

int resolve(int n)
{
    int sum = 0;
    while (n)
    {
        int decade = n % 10;
        sum += (decade * decade);
        n /= 10;
    }
    return sum;
}

int main()
{
    Solution sol;
    bool res;
    cout << sol.isHappy(69);
}