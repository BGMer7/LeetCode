#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int unhappyFriends(int n, vector<vector<int>> &preferences, vector<vector<int>> &pairs)
    {
        unordered_map<int, unordered_set<int>> m;
        for (auto p : pairs)
        {
            int a = p[0], b = p[1];
            vector<int> friendA = preferences[a];
            vector<int> friendB = preferences[b];
            for (int fa : friendA)
            {
                if (fa != b)
                    m[a].insert(fa);
                else
                    break;
            }

            for (int fb : friendB)
            {
                if (fb != a)
                    m[b].insert(fb);
                else
                    break;
            }
        }
        // cout << *m[1].begin() << endl;

        int res = 0;
        for (int i(0); i < n; ++i)
        {
            if (m[i].size() == 0)
                continue;
            else
                for (int f : m[i])
                    // cout << "f" << f << " m" << i << endl;
                    if (m[f].count(i))
                    {
                        ++res;
                        break;
                    }
        }
        return res;
    }
};

int main() {}