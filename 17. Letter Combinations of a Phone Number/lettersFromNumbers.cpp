#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        int size = digits.size();
        if (size == 0)
            return res;
        queue<string> que;

        for (int i = 0; i < phoneMap[digits[0]].size(); i++)
        {
            string str;
            str.push_back(phoneMap[digits[0]][i]);
            que.push(str);
        }

        string head;

        for (int i = 1; i < size; i++)
        {
            int length = que.size();
            while (length--)
            {
                for (int j = 0; j < phoneMap[digits[i]].size(); j++)
                {
                    head = que.front();
                    head += phoneMap[digits[i]][j];
                    que.push(head);
                }
                que.pop();
            }
        }

        while (!que.empty())
        {
            res.push_back(que.front()); //队头元素存储至res
            que.pop();                  //队头出队
        }
        returns res;
    }

private:
    map<char, string> phoneMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};
};

class Solution1
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;                                                                                                                       //用于输出向量
        map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}}; //映射map哈希表
        int size = digits.size();                                                                                                                 //输入字符串产长度
        queue<string> que;                                                                                                                        //新建队列

        //先将第一个元素对应的码表入队
        for (int j = 0; j < m[digits[0]].size(); j++)
        {
            string str;
            str.push_back(m[digits[0]][j]); //char转string
            que.push(str);                  //string入队
        }
        string s; //用于存储队头元素
        for (int i = 1; i < size; i++)
        {
            int length = que.size(); //当前队列长度
            while (length--)
            {
                for (int j = 0; j < m[digits[i]].size(); j++)
                {
                    s = que.front();
                    s = s + m[digits[i]][j]; //队头元素加上新元素
                    que.push(s);             //入队
                }
                que.pop(); //队头出队
            }
        }
        while (!que.empty())
        {
            res.push_back(que.front()); //队头元素存储至res
            que.pop();                  //队头出队
        }
        return res; //返回
    }
};

main()
{
    Solution s;
    string digits = "124";
    s.letterCombinations(digits);

    
}