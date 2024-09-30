#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: September 29, 2024
 * Problem: Remove Duplicates from Sorted Array II
 * Level: Medium
 * Neetcode Course: Advanced Algorithms
 * Neetcode Topic: Two Pointers
 */

int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    int j = 0;

    while (j < nums.size())
    {
        if (j < nums.size() - 1 && nums[j] == nums[j + 1])
        {
            nums[i] = nums[j];
            nums[i + 1] = nums[j];

            while (j < nums.size() && nums[j] == nums[i])
            {
                j++;
            }

            i += 2;
        }
        else
        {
            nums[i] = nums[j];
            i++;
            j++;
        }
    }

    return i;
}
