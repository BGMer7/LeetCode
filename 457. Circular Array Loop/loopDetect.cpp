#include<vector>
using namespace std;



class Solution
{
public:
    inline int sign(int y) //取符号
    {
        return y > 0 ? 1 : -1;
    }
    inline int fix(int i, int n)
    { //把i修正到0~n-1的范围
        return ((i % n) + n) % n;
    }

    bool circularArrayLoop(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 1000 || nums[i] < -1000)
            { //跳过访问过的
                continue;
            }
            int flag = sign(nums[i]) * (1000 + i + 1); //同号标记
            for (int j = i; sign(nums[i]) == sign(nums[j]) && (nums[j] >= -1000 && nums[j] <= 1000);)
            {
                int pre = j;
                j = fix(j + nums[j] + n, n); //前进
                if (sign(nums[i]) == sign(nums[j]) && nums[j] == flag)
                {
                    return true;
                }
                nums[pre] = flag; //标记访问过的点
            }
        }
        return false;
    }
};

int main() {}