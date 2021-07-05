#include <set>
#include <iostream>

using namespace std;

void print(set<int> c)
{
    for (set<int>::iterator i = c.begin(); i != c.end(); i++)
    {
        cout << *i << endl;
    }
}

void print(multiset<int> c)
{
    for (set<int>::iterator i = c.begin(); i != c.end(); i++)
    {
        cout << *i << endl;
    }
}

int main()
{
    set<int> A;
    A.insert(1);
    A.insert(1);
    A.insert(2);
    cout << A.size() << endl;
    multiset<int> B;
    B.insert(1);
    B.insert(1);
    B.insert(7);
    B.insert(8);
    B.insert(5);
    B.insert(2);
    // cout << *B.rbegin() << endl;
    // cout << *B.rend() << endl;
    // cout << *B.end() << endl;
    // cout << *B.begin() << endl;
    // cout << B.size() << endl;
    print(B);
    cout << endl;
    B.erase(6);
    B.erase(B.find(1));

    print(B);

}