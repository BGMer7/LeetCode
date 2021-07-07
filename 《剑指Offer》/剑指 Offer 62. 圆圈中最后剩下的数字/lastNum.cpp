#include <vector>
#include <iostream>

using namespace std;

class Solution
{
private:
    int loop(int m, int n)
    {
        if (m == 0)
            return 0;
        int x = loop(m - 1, n);
        return (x + n) % m;
    }

public:
    int lastRemaining(int n, int m)
    {
        return loop(n, m);
    }
};

int main() {}