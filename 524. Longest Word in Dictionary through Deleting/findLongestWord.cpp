#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string findLongestWord(string s, vector<string> &dictionary)
    {
        // int n = dictionary.size();
        // int len[n];
        // for(int i(0); i<n;++i)
        // {
        //     len[i] = dictionary[i].size();
        // }
        string res = "";
        for (int i = 0; i < dictionary.size(); i++)
        {
            // 首先判断一波是否可以进行判断，如果是长度不够或者长度相等字典序大的直接剪枝
            if (res.length() > dictionary[i].length() || (res.length() == dictionary[i].length() && res.compare(dictionary[i]) < 0))
            {
                continue;
            }
            // 判断
            if (isSubstring(s, dictionary[i]))
            {
                res = dictionary[i];
            }
        }
        return res;

    }

    bool isSubstring(string s, string dics)
    {
        int s_ptr = 0, d_ptr = 0;
        while (s_ptr < s.size() && d_ptr < dics.size())
        {
            if (s[s_ptr] == dics[d_ptr])
                ++d_ptr;
            ++s_ptr;
        }
        return d_ptr == dics.size();
    }
};

int main()
{

}