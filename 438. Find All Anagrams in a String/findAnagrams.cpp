#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class SolutionHash
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int winSize = p.size();
        unordered_map<char, int> map;
        vector<int> res;
        int need = p.size();
        for(char ch: p){ // 这一步太耗时
            map[ch] = count(p.begin(), p.end(), ch);
        }
        int left = 0, right = left + winSize - 1;
        while (right < s.size())
        {
            bool isAnagram = true;
            string sub = s.substr(left, winSize);
            for(auto m: map){
                if(count(sub.begin(), sub.end(), m.first) != m.second)
                    isAnagram = false;

            }
            if(isAnagram)
                res.push_back(left);

            ++left;++right;
        }
        return res;
    }
};

class SolutionVector
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res, need(128), window(128);
        if (p.size() > s.size() || s.size() == 0)
            return res;
        for (char ch : p)
            need[ch]++;

        int left = 0, right = left + p.size() - 1;
        string sub = s.substr(left, p.size());
        for (auto ch : sub)
            window[ch]++;
        while (right < s.size())
        {
            if (window == need)
                res.push_back(left);
            window[s[++right]]++;
            window[s[left++]]--;
        }
        return res;
    }
};

int main()
{
    string s("abab");
    string t("ab");
    SolutionVector sol;
    string sub = s.substr(0, t.size());
    vector<int> res, need(128), window(128), windows(128);
    for(auto ch: sub)
        window[ch]++;
    for (int i = 0; i < t.size() - 1; i++)
        windows[s[i]]++;
    cout << (window == windows);
    cout << endl;
    for(auto c:window)  cout << c<< " ";
    cout <<endl;
    for(auto c:windows) cout << c <<" ";
}