#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> s;
    stack<int> m;

public:
    /** initialize your data structure here. */
    MinStack()
    {
        m.push(INT_MAX);
    }

    void push(int x)
    {
        s.push(x);
        int minNumber;
        minNumber = m.top() < x ? m.top() : x;
        m.push(minNumber);
    }

    void pop()
    {
        s.pop();
        m.pop();
    }

    int top()
    {
        return s.top();
    }

    int min()
    {
        return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

int main() {}