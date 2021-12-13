#include <iostream>
#include <ctype.h>

using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for(int i(0); i<s.size(); ++i) {
            if(isupper(s[i])) {
                s[i] += 32;
            }
        }
        return s;
    }
};

int main() {
    char ch = 'c';
    char* a = &ch;
    printf("%p\n", a);
    cout << *a << endl;

    char a1[10];
    printf("%p\n", a1);

}