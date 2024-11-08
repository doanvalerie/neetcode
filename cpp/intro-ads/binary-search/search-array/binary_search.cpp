#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 28, 2024
 * Problem: Binary Search
 * Level: Easy
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Search Array
 */

int search(vector<int> &nums, int target)
{
    int L = 0;
    int R = nums.size() - 1;

    while (L <= R)
    {
        int mid = (L + R) / 2;

        if (target < nums[mid])
        {
            R = mid - 1;
        }
        else if (target > nums[mid])
        {
            L = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}