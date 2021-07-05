#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    set<string> st;
    vector<string> res;

    void helper(int index, string s)
    {
        if (index == s.size() - 1)
        {
            st.insert(s);
            return;
        }

        for (int i(index); i < s.size(); ++i)
        {
            if (i > index && s[i - 1] == s[i])
                continue;

            swap(s[index], s[i]);
            helper(index + 1, s);
            swap(s[index], s[i]);
        }
    }

public:
    vector<string> permutation(string s)
    {
        sort(s.begin(), s.end());
        helper(0, s);
        res.assign(st.begin(), st.end());
        return res;
    }
};

int main() {}