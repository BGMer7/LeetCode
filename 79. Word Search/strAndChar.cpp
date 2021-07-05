#include <string>
#include <iostream>
using namespace std;

int main(){
    string s("ABCD");
    char c = 'E';
    string st("ABCDE");
    s.push_back(c);
    if(s==st)
    {
        cout << "equal";
    }
}