#include <vector>
#include <set>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int start = 0;
        const int len = 10;
        const int size = s.size();
        set<string> lib;
        set<string> res;
        vector<string> resV;
        if (size <= 10)
            return resV;
        while (start + len <= size)
        {
            string sub = s.substr(start, len);
            if (lib.find(sub) != lib.end())
                res.insert(sub);
            else
                lib.insert(sub);
            // cout << start << endl;
            ++start;
        }
        resV.assign(res.begin(), res.end());
        return resV;
    }
};

int main() {}