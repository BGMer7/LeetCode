#include <string>
#include <iostream>

using namespace std;


class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int i = left;
        int res=0;
        while(i<=right)
            res&=i;
        return res;

    }
};

int main() {
    cout << (5 and 6 and 7) << endl; // 输出1，true，意思和5&&6&&7是一样的
    cout << (5 & 6) << endl;
    cout << (6 & 7) << endl;
    cout << (5 & 6 & 7) << endl;
    cout << (10 & 11) << endl;
}