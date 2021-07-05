#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        return haystack.find(needle);
    }

    int strInStr(string haystack, string needle)
    {
        if (needle == "")
            return 0;
        int res = -1;
        for (int i = 0; i < haystack.size(); i++)
        {
            if (haystack[i] == needle[0])
            {
                int left = i;
                cout << i << endl;
                if (haystack.substr(i, needle.size()) == needle)
                {
                    res = i;
                    return res;
                }
            }
        }
        cout << res;
        return res;
    }
};

main()
{
    string haystack("sdadadjasdfasdfasdf");
    string needle("adj");
    int res = -1;
    for (int i = 0; i < haystack.size(); i++)
    {
        if (haystack[i] == needle[0])
        {
            int left = i;
            cout << i << endl;
            if (haystack.substr(i, needle.size()) == needle)
            {
                res = i;
                cout<< res;
                break;
                return res;
            }
        }
    }
    cout << res;
    return res;
}