#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    { 
        int size=(1<<n); // 需要2的n次方个数
        vector<int> res;
        for(int i(0);i<size;i++){
            int grayCode = i^(i>>1);
            res.push_back(grayCode);
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> res = sol.grayCode(4);
    for(int num:res) 
    {
        cout << num <<" ";
    }
    cout <<endl;
}