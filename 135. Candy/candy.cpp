#include <stdio.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

// You are giving candies to these children subjected to the following requirements :
//     Each child must have at least one candy.
//     Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.

class Print
{
public:
    void printVectorinSort(vector<int> &vector)
    {
        sort(vector.begin(), vector.end());
        for (int i = 0; i < vector.size(); i++)
        {
            cout << vector[i] << " ";
        }
        cout << endl;
    }

    void printVector(vector<int> &vector)
    {
        for (int i = 0; i < vector.size(); i++)
        {
            cout << vector[i] << " ";
        }
        cout << endl;
    }
};

class Solution : public Print
{
public:
    int candy(vector<int> &ratings)
    {
        int children = ratings.size();
        if (ratings.size() < 2)
            return children;
        vector<int> num(children, 1);
        Print print;
        print.printVector(num);
        int i = 0;
        while (i < children - 1)
        {
            if (ratings[i] < ratings[i + 1])
                num[i + 1] = num[i] + 1;
            i++;
        }
        print.printVector(num);
        while (i > 0)
        {
            if (ratings[i] < ratings[i - 1])
                num[i - 1] = max(num[i] + 1, num[i - 1]);
            i--;
        }
        print.printVector(num);
        return accumulate(num.begin(), num.end(), 0);
    }
};

int main()
{
    vector<int> ratings{1, 3, 5, 7, 6, 7, 6, 4, 5, 2};
    Solution sol;
    cout << sol.candy(ratings) << endl;
}
