#include <array>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // if (m == 0)
        //     nums1.assign(nums2.begin(), nums2.end());

        // int pos = m + n - 1;
        // int i = m - 1;
        // int j = n - 1;
        // while (pos != 0)
        // {
        //     // nums1[i] >= nums2[j]?nums1[pos] = nums1[i] : nums1[pos] = nums[j];

        //     if (nums1[i] >= nums2[j])
        //     {
        //         nums1[pos] = nums1[i];
        //         --i;
        //         --pos;
        //     }
        //     else
        //     {
        //         nums1[pos] = nums2[j];
        //         --j;
        //         --pos;
        //     }

        //     if (i == -1)
        //     {
        //         nums1.assign(nums2.begin(), nums2.begin() + pos);
        //         break;
        //     }
        //     if (j == -1)
        //         break;
        //     // for (int i = 0; i < m + n; i++)
        //     // {
        //     //     cout << " " << nums1[i];
        //     // }
        //     // cout << endl;
        // }

        // for (int i = 0; i < m + n; i++)
        // {
        //     cout << " " << nums1[i];
        // }
        int pos = m + n - 1;
        while (n != 0)
        {
            // nums1[i] >= nums2[j]?nums1[pos] = nums1[i] : nums1[pos] = nums[j];

            if (m == 0 || nums1[m - 1] <= nums2[n - 1])
            {
                nums1[pos--] = nums2[--n];
            }
            else
            {
                nums1[pos--] = nums1[--m];
            }
        }
    }
};

main()
{
    vector<int> nums1{1, 3, 6, 7, 8, 0, 0, 0, 0};
    vector<int> nums2{1, 2, 3, 4};
    vector<int> nums3{2, 0};
    vector<int> nums4{1};
    Solution sol;
    sol.merge(nums3, 1, nums4, 1);
}