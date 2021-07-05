#include <vector>
#include <string>

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        // 先构造一个哈希表，用于存放每个char对应的出现次数
        unordered_map<char, int> m;
        for (char c : s)
            ++m[c];

        string stk;

        // 构造一个哈希表，用于判断这个char是不是已经在目标string中了，如果已经在了，就不对它操作了，除非他被pop
        // 因此在后续的遍历中，如果这个char被pop了，还需要把这个char对应的bool改成false
        unordered_map<char, bool> isInStack;

        for (char c : s)
        {
            if (!isInStack[c]) // 目前遍历的这个char还没有被放进去，我们考虑以下要不要现在放在string尾部
            {
                // 如果string的尾部char比现在这个char答，那就不满足字典序递增的规则
                // 进一步判断要不要换掉string尾巴，用这个char
                while (!stk.empty() && stk.back() > c)
                {
                    // 判断后面还有没有这个元素了，如果后面已经没了，那就不可能这里再把它pop了，因为后面没了，这里pop的话，后面没有机会补救了
                    if (m[stk.back()])
                    {
                        // 如果后面还有这个元素，那就可以硬气一点，现在的排列不符合字典序，把它换掉
                        // 换掉之后它就不在这个string中了，把isInStack改成false，然后pop
                        isInStack[stk.back()] = false;
                        stk.pop_back();
                    }
                    else
                        break; // 后面没有了，那别搞了
                }
                stk.push_back(c);    // 把这个符合字典序的元素放在string尾部
                isInStack[c] = true; // 这个元素加进来了，把bool改为true
            }
            --m[c]; // 这个元素遍历过了，剩余的它又要少一个了
        }
        return stk;
    }
};

int main() {}