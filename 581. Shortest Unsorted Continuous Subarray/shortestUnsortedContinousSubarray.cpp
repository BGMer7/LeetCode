#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        stack<int> st;
        int l = nums.size() - 1;
        int r = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!st.empty() && nums[st.top()] > nums[i])
            {
                l = min(l, st.top());
                st.pop();
            }
            st.push(i);
        }
        st = stack<int>();
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] < nums[i])
            {
                r = max(r, st.top());
                st.pop();
            }
            st.push(i);
        }
        return (r > l) ? r - l + 1 : 0;
    }
};

class SolutionSort
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1 || n == 0)
            return 0;
        vector<int> copy;
        copy.assign(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        int left = n - 1, right = 0;
        for (int i(0); i < n; ++i)
            if (nums[i] != copy[i])
                left = min(left, i);

        for (int i(n - 1); i >= 0; --i)
            if (nums[i] != copy[i])
                right = max(right, i);

        return right - left < 0 ? 0 : right - left + 1;
    }
};

int main() {}