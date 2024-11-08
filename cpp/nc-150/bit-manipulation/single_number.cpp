#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 9, 2024
 * Problem: Single Number
 * Level: Easy
 * Neetcode Course: Neetcode 150
 * Neetcode Topic: Bit Manipulation
 */

int singleNumber(vector<int> &nums)
{
    int res = 0;

    for (int num : nums)
    {
        res ^= num;
    }

    return res;
}