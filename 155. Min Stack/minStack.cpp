#include <stack>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class MinStack
{
private:
    stack<int> x_stack, min_stack;

public:
    /** initialize your data structure here. */
    MinStack()
    {

    }

    void push(int x)
    {
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }

    void pop()
    {
        x_stack.pop();
        min_stack.pop();
    }

    int top()
    {
        return x_stack.top();
    }

    int getMin()
    {
        return min_stack.top();
    }
};



/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack minStack;
    minStack.push(0);
    minStack.push(1);
    minStack.push(0);
    int get_min = minStack.getMin(); // return -3
    cout << get_min << endl;
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
    return 0;
}