#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    vector<string> vec1;
    vector<string> vec2;
    void resolve(string s) {
        iint i=0;
        while(i<s.size()) {
            if(s[i]=='0') ++i;
            else break;
        }
            
        int j=s.size()-1;
        while(j>=i) {
            if(s[j]=='0') --j;
            else break;
        }

        s=s.substr(i, j-i+1);
    }


public:
    int compareVersion(string version1, string version2) {
        version1+='.';
        version2+='.';
        string seg("");
        for(char c: version1) {
            if(c=='.') {
                vec1.push_back(seg);
                seg.clear();
            }
            else 
                seg.push_back(c);
        }
        for (char c : version2)
        {
            if (c == '.')
            {
                vec2.push_back(seg);
                seg.clear();
            }
            else
                seg.push_back(c);
        }
        if(vec1.size()!=vec2.size()) return false;
        int n = vec1.size();
        for(int i(0); i<n; ++i) {
            resolve(vec1[i]);
            resolve(vec2[i]);
            if(vec1[i]!=vec2[i])
                return false;
        }
        return true;
    }
};

void resolve(string &s) {
        int i=0;
        while(i<s.size()) {
            if(s[i]=='0') ++i;
            else break;
        }
            
        
        int j=s.size()-1;
        while(j>=i) {
            if(s[j]=='0') --j;
            else break;
        }
        cout << i << endl;
        cout << j << endl;

        s=s.substr(i, j-i+1);
    }


int main(){
    string s("");resolve(s);
    cout << s << endl;
}