#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        if (A > E)
            return computeArea(E, F, G, H, A, B, C, D);

        int area1 = (D - B) * (C - A), area2 = (H - F) * (G - E);
        if (E > C || F > D || H < B)
            return area1 + area2;
        else
            return area1 + area2 - (min(G, C) - max(A, E)) * (min(D, H) - max(B, F));
    }
};

int main()
{
}