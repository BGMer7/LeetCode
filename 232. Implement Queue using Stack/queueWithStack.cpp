#include <stack>
#include <iostream>

using namespace std;

class MyQueue
{
private:
    stack<int> stk_in, stk_out;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        stk_in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (stk_out.empty())
        {
            while (!stk_in.empty())
            {
                int n = stk_in.top();
                stk_in.pop();
                stk_out.push(n);
            }
        }
        int x = stk_out.top();
        stk_out.pop();
        return x;
    }

    /** Get the front element. */
    int peek()
    {
        if (stk_out.empty())
        {
            while (!stk_in.empty())
            {
                int n = stk_in.top();
                stk_in.pop();
                stk_out.push(n);
            }
        }
        int x = stk_out.top();
        return x;
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return (stk_in.empty() && stk_out.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyQueue myQueue;}