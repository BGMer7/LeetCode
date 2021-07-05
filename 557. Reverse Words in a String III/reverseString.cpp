#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string res = "";
        string tmp = "";
        stringstream ss(s);
        if (s.empty())
            return res;
        while (ss >> tmp)
        {
            reverse(tmp.begin(), tmp.end());
            res += tmp + ' ';
        }
        res.pop_back();
        return res;
    }
};

int main(){
    string s1 = "12", s2 = "34";
    string s = s1+s2;
    cout << s;
    string ss = "1213";
    cout << (s<ss) <<endl;

}