#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        const int len = secret.size();
        int bulls = 0, cows = 0;
        unordered_map<char, int> s, g;
        for(int i(0); i<len; ++i) {
            char cs = secret[i], cg = guess[i];
            if(cs == cg) 
                ++bulls;
            
            ++s[cs];
            ++g[cg];
        }

        for(auto p: g) {
            char c = p.first;
            int t = p.second;
            cows+=min(t, s[c]);
        }

        cows -= bulls;
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};