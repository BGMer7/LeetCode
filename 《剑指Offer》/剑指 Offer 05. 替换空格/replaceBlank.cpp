#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string replaceSpace(string s)
    {
        string res("");
        for(auto ch: s) {
            if(ch == ' ') res+="%20";
            else res+=ch;
        }
        return res;
    }
};

int main() {
    string s("we are the world.");
    Solution sol;
    cout << sol.replaceSpace(s) << endl;
}
