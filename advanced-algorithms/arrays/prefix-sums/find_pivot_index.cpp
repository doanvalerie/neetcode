#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 16, 2024
 * Problem: Find Pivot Index
 * Level: Easy
 * Neetcode Course: Advanced Algorithms
 * Neetcode Topic: Prefix Sums
 */

int pivotIndex(vector<int> &nums)
{
    vector<int> prefix;
    int total = 0;

    for (int num : nums)
    {
        total += num;
        prefix.push_back(total);
    }

    vector<int> postfix;
    total = 0;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        total += nums[i];
        postfix.push_back(total);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (prefix[i] == postfix[nums.size() - 1 - i])
        {
            return i;
        }
    }

    return -1;
}