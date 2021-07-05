#include <iostream>
#include <string>
using namespace std;

// class Solution // 一个一个情况分类太难了
// {
// public:
//     bool isNumber(string s)
//     {
//         int point = -1, e_index = -1, sign = -1;
//         int start = 0, end = s.size() - 1;
//         while (start < s.size() && s[start] == ' ')
//             ++start;
//         while (end >= 0 && s[end] == ' ')
//             --end;

//         s = s.substr(start, end - start + 1);
//         // int i=index;
//         for (int i(0); i < s.size(); ++i)
//         {
//             if (s[i] == '.')
//                 point == -1 ? point = i : return false;

//             if (s[i] == 'e' || s[i] == 'E')
//                 e_index == -1 ? e_index = i : return false;

//             if (s[i] == '+' || s[i] == '-')
//                 e_index == -1 ? e_index = i : return false;
//         }
//         if (point > e_index)
//             return false;
        
//         if(point = -1)
//     }

//     bool isSigned(string s)
//     {
//         int cnt = 0;
//         for (char c : s)
//         {
//             if (c == '+' || c == '-')
//                 ++cnt;
//         }
//         return cnt < 2;
//     }
// };

int main()
{
    string s("sba");
    cout << s.substr(0, 1);
}