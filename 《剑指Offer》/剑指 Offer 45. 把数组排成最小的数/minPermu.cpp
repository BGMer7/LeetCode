#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string minNumber(vector<int> &nums)
    {
        // static const int n=nums.size();
        // int m = n;
        vector<string> strs;
        string res("");
        for (int num : nums)
            strs.push_back(to_string(num));
        sort(strs.begin(), strs.end(), [](string &a, string &b)
             { return a + b < b + a; });
        for (string str : strs)
            res = res + str;
        return res;
    }
};

int main() {}