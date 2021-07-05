#include <iostream>
using namespace std;

class Solution
{
public:
    int add(int a, int b)
    {
        while (b != 0)
        {
            int c = unsigned(a & b) << 1; //进位
            a = a ^ b;
            b = c;
        }
        return a;
    }
};

int main() {
    Solution sol;
    cout << sol.add(12,32);
}