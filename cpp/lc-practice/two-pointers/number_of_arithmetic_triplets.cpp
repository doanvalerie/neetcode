#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 24, 2024
 * Problem: 2367. Number of Arithmetic Triplets
 * Level: Easy
 * Topics: Array, Hash Table, Two Pointers, Enumeration
 */

int arithmeticTriplets(vector<int> &nums, int diff)
{
    int count = 0;
    int i = nums.size() - 3;
    int j = nums.size() - 2;
    int k = nums.size() - 1;

    while (i >= 0)
    {
        if (nums[k] - nums[j] < diff)
        {
            j--;
        }
        else if (j >= 0 && nums[k] - nums[j] > diff)
        {
            k--;
        }

        if (i >= j || nums[j] - nums[i] < diff)
        {
            i--;
        }
        else if (i >= 0 && nums[j] - nums[i] > diff)
        {
            j--;
        }

        if (i < 0 || j < 0 || k < 0)
        {
            break;
        }
        if (nums[k] - nums[j] == diff && nums[j] - nums[i] == diff)
        {
            count++;
            i--;
            j--;
        }
    }

    return count;
}