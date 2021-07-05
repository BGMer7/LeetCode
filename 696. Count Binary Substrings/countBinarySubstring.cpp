#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int count = 0;

    int countBinarySubstrings(string s)
    {
        vector<int> serial;
        char c = s[0];
        int consecution = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
            {
                ++consecution;
            }
            else
            {
                serial.push_back(consecution);
                consecution = 1;
                c = s[i];
            }
        }
        serial.push_back(consecution);
        // for(auto i : serial)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        int ans =0;
        for (int i = 0; i < serial.size()-1; i++)
        {
            ans += min(serial[i], serial[i + 1]);
            //cout << ans <<endl;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums{0,0,1,1,0,1};
    string s = "001101";
    Solution sol;
    cout << sol.countBinarySubstrings(s);
}