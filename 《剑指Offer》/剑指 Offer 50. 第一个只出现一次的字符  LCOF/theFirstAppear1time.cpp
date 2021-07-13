#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> m;
        for(char c: s) 
            ++m[c];
        
        for(auto c: s) 
            if(m[c]==1)
                return c;
        
        return ' ';
    }
};

int main() {}