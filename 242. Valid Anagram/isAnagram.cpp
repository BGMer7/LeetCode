#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s("asdfghjk");
    string t("asdfghjk");
    if (s.size() != t.size())
        return false;
    unordered_map<char, int> s_map, t_map;
    for (auto c : s)
    {
        ++s_map[c];
    }
    for (auto c : t)
    {
        ++t_map[c];
    }
    cout << (s_map == t_map);

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    cout << (s == t);
}