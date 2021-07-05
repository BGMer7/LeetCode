#include <stack>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> pushed, vector<int> popped)
    {
        int m = pushed.size(), n = popped.size();
        if (m != n)
            return false;

        stack<int> stk;
        int out = 0;
        for (int in(0); in < n; in++)
        {
            while (in < m && (!stk.empty() && stk.top() != popped[out]))
            {
                stk.push(pushed[in++]);
                cout << "push" << endl;
            }
            while (out < n && (!stk.empty() && stk.top() == popped[out]))
            {
                stk.pop();
                ++out;
                cout << "pop" << endl;
            }
        }
        return stk.empty();
    }
};

int main()
{
    vector<int> pushed{1, 2, 3, 4, 5};
    vector<int> popped{4, 5, 3, 2, 1};
    Solution sol;
    cout << sol.validateStackSequences(pushed, popped);
    
}