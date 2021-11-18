#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        const int len = words.size();
        unordered_map<int, int> map;
        for (int i = 0; i < len; ++i)
        {
            int mask = 0;
            string word = words[i];
            const int wordLength = word.size();
            for (int j = 0; j < wordLength; ++j)
                mask |= 1 << (word[j] - 'a');

            if (map.count(mask))
            {
                if (wordLength > map[mask])
                    map[mask] = wordLength;
            }
            else
                map[mask] = wordLength;
        }

        int maxProd = 0;
        for (auto [mask1, _] : map)
        {
            int wordLength1 = map[mask1];
            for (auto [mask2, _] : map)
                if (!(mask1 & mask2))
                {
                    int wordLength2 = map[mask2];
                    maxProd = max(maxProd, wordLength1 * wordLength2);
                }
        }
        return maxProd;
    }
};