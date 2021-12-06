#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        const int len1=s.size(), len2=goal.size();
        if(len1!=len2) return false;
        if (s == goal) {
            vector<int> count(26);
            for (int i = 0; i < s.size(); i++) {
                count[s[i] - 'a']++;
                if (count[s[i] - 'a'] > 1) {
                    return true;
                }
            }
            return false;
        }

        
        vector<int> diff1;
        vector<int> diff2;
        bool isRepeat = false;
        for(int i(0); i<len1; ++i) {
            if(s[i]!=goal[i]) {
                diff1.push_back(s[i]);
                diff2.push_back(goal[i]);
            }
            if(diff1.size()>2)
                return false;
        }
        if(diff1.size()!=2) return false;
        return diff1[0]==diff2[1] && diff1[1]==diff2[0];
    }
};
int main() {}