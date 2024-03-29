#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        const int len = s.size();
        if (len <= 1)
            return s;
        int start, maxLen = 0;
        for (int i = 1; i < len; i++)
        {
            // 寻找以i-1,i为中点偶数长度的回文
            int low = i - 1, high = i;
            // 循环的条件是低地址大于零且高地址不越界，并且低地址字符和高地址字符相等
            while (low >= 0 && high < len && s[low] == s[high])
            {
                low--;
                high++;
            }

            if (high - low - 1 > maxLen)
            {
                maxLen = high - low - 1;
                start = low + 1;
            }

            //寻找以i为中心的奇数长度的回文
            low = i - 1;
            high = i + 1;

            while (low >= 0 && high < len && s[low] == s[high])
            {
                low--;
                high++;
            }

            if (high - low - 1 > maxLen)
            {
                maxLen = high - low - 1;
                start = low + 1;
            }
        }
        return s.substr(start, maxLen);//原来还有这个函数...
    }
};

int main()
{
    Solution sol;
    string s("asdgasibsadfhsgfjshgkywubvasfjhsavdfjkilausfghasdfnbsakdljfbuifghjklkjhgfdsasdfghjkklqwertyuioppoiuytrewqhsdgjhgvaksucsdbhjargfqwueygsdjafbvdsajkhfgbskjahdgfsjkdhgfiqwyegfsjdahvxcvnbajhdgsafysdatgfuqyewrqwmbasdfjkgsaiuydgfkjhdkjhvxcjqwerqpweorupsoihfkxzljcvblikasutgfqewiyubfalsdfjkbjhxzgvkyahbsdfjliughqwreewqpohcvxkasdflyglkjhxcvzblhqewrgmnxbzcbvvoaidusadfweqtrewyvbaszxcgdg");
    cout << sol.longestPalindrome(s);
    return 0;
}