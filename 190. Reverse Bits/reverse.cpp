#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = 0;
        int i=32;
        while(i--){
            res<<=1;
            res+=n&1;
            n>>=1;
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.reverseBits(15);
}