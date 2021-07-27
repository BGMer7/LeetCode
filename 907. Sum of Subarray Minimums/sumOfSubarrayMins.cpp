#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
3 1 2 4
3 1 1 1
  1 1 1
    2 2
      4
3+1+1+1+1+1+1+2+2+4=17
*/

class Solution
{
private:
    const int _mod_ = 1000000007;

public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int sz = arr.size(), res = 0;
        for (int i(0); i < sz; ++i)
        {
            int m = arr[i];
            for (int j(i); j < sz; ++j)
            {
                m = min(arr[j], m);
                res %= _mod_;
                res += m;
            }
        }
        return res;
    }
};

class SolutionStack
{
private:
    const int _mod_ = 1000000007;
    stack<int> s;

public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int sz = arr.size(), res = 0;
        arr.push_back(0);
        for (int i(0); i < sz; ++i)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
            {
                int index = s.top();
                s.pop();
                int prev_index = s.empty() ? -1 : s.top();
                int prev_cnt = index - prev_index;
                int rear_cnt = i - index;
                res += arr[index] * prev_cnt * rear_cnt;
                res %= _mod_;
            }
            s.push(i);
        }
        return res;
    }
};

int main() {}