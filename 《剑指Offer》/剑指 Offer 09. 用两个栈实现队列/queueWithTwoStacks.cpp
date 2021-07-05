#include <stack>
#include <iostream>
using namespace std;

class CQueue
{
private:
    stack<int> s1, s2;

public:
    CQueue()
    {
        stack<int> s1, s2;
        cout << "create a queue" << endl;
    }

    ~CQueue()
    {
        cout << "queue destoried" << endl;
    }

    void appendTail(int value)
    {
        s1.push(value);
    }

    int deleteHead()
    {
        if (!s2.empty())
        {
            int head = s2.top();
            s2.pop();
            return head;
        }
        else if (s1.empty())
            return -1;
        else
        {
            while (!s1.empty())
            {
                int val = s1.top();
                s1.pop();
                s2.push(val);
            }
            int head = s2.top();
            s2.pop();
            return head;
        }
        return -1;
    }
};

// class CQueue
// {
//     stack<int> stack1, stack2;

// public:
//     CQueue()
//     {
//         while (!stack1.empty())
//         {
//             stack1.pop();
//         }
//         while (!stack2.empty())
//         {
//             stack2.pop();
//         }
//     }

//     void appendTail(int value)
//     {
//         stack1.push(value);
//     }

//     int deleteHead()
//     {
//         // 如果第二个栈为空
//         if (stack2.empty())
//         {
//             while (!stack1.empty())
//             {
//                 stack2.push(stack1.top());
//                 stack1.pop();
//             }
//         }
//         if (stack2.empty())
//         {
//             return -1;
//         }
//         else
//         {
//             int deleteItem = stack2.top();
//             stack2.pop();
//             return deleteItem;
//         }
//     }
// };

int main()
{
    CQueue queue;
}