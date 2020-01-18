#include <iostream>
#include <unordered_map>
using namespace std;

class BruteForceSol
{
public:
    int findTheLongestSubstring(string s)
    {
        int maxLength = 0;
        string maxSubstring;
        for (int i = 0; i < s.size(); i++)
        {
            if (maxSubstring.find(s[i]) != -1)
                maxSubstring.erase(0, maxSubstring.find(s[i]) + 1); // 如果新来的字符在最大字串中已经出现，把截止新字符重新出现前的字符都删掉
            maxSubstring += s[i];
            maxLength < maxSubstring.size() ? maxLength = maxSubstring.size() : maxLength;
        }
        return maxLength;
    }
};

class SlidingWindow
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int max = 1;
        int left = 1;int right = 1;
        if (s.size() == 0)
            return 0;
        unordered_map<char, int> hashmap; //创建从字符到字符所在的位置的映射，位置从1开始
        for (int i = 0; i < s.size(); i++)
        {
            if (hashmap[s[i]] >= left)    //hashmap[s[i]]默认值是0，而hashmap[s[i]]>=left说明s[i]对应的字符
                left = hashmap[s[i]] + 1;
                cout << left << " "; //以及出现在hashmap[s[i]]对应的位置。令left=hashmap[s[i]]+1即可
            hashmap[s[i]] = i + 1;        //字符s[i]对应的位置为i+1；
            right = hashmap[s[i]];
            cout << right << endl; //right指向第i位
            for (const auto &n : hashmap)
            {
                std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
            }
            max = (max < right - left + 1) ? (right - left + 1) : max;
        }
        return max;
    }
};

int main()
{
    BruteForceSol s1;
    SlidingWindow s2;
    string s = "dvdf";
    cout << s1.findTheLongestSubstring(s) << endl;
    cout << s2.lengthOfLongestSubstring(s) << endl;
    
}