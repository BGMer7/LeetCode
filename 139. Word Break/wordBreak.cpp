#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i(1); i <= n; ++i)
        {
            for (auto word : wordDict)
            {
                int len = word.size();
                if (i - len >= 0 && s.substr(i - len, len) == word)
                    // dp[i] = true; // 这样不对，这样只要是最后几个字母是字典里的词，结果总是true，没有和前面的结果结合起来
                    // 必须要是刚好从上一个单词结束的地方开始，这一段构成的单词在字典中才可以
                    dp[i] = dp[i - len] || dp[i]; // 如果没有|| dp[i] 会导致后面的，例如gs，也是其中一个子串，会把之前的结果给冲掉
                    for(auto s:dp){
                        cout << s <<" ";
                    }
                    cout << endl;
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution sol;
    vector<string> wordDict{"dog", "s", "gs"};
    bool res = sol.wordBreak("dogs", wordDict);
}