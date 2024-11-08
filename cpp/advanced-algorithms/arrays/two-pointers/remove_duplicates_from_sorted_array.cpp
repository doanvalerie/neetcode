#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: September 29, 2024
 * Problem: Remove Duplicates from Sorted Array
 * Level: Easy
 * Neetcode Course: Advanced Algorithms
 * Neetcode Topic: Two Pointers
 */

int removeDuplicates(vector<int> &nums)
{
    int j = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[j])
        {
            nums[++j] = nums[i];
        }
    }

    return j + 1;
}