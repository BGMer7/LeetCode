#include <iostream>
using namespace std;

string test(string s)
{
    string str("world");
    s.pop_back();
    cout << s << endl;
    cout << str << endl;
    return s;
}

string testRefer(string &s)
//the arg is also changed
{
    string str("world");
    s.pop_back();
    cout << s << endl;
    cout << str << endl;
    return s;
}

main()
{
    string s("hello");
    test(s);
    testRefer(s);
    cout << s << endl;
}