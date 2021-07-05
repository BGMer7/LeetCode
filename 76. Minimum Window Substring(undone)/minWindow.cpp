#include <vector>
#include <iostream>
#include <unordered_map>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    unordered_map<char, int> ltr, cnt;

    //bool check(){}
};



int main()
{

    unordered_map<char, int> ltr, cnt;
    
    string t("ssdlfasduylkadngllbkjdsfbgldbgdhurhewl");
    for (const auto &c : t)
    {
        ++ltr[c];
    }
    cout << ltr['d'] << endl;

    vector<int> need(128,0);
    for(char c:t){
        need[c]++;
    }
    for(auto c:need){
        cout << " " << need[c] << " ";
    }
}