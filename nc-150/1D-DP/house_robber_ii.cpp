#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 18, 2024
 * Problem: House Robber II
 * Level: Medium
 * Neetcode Course: Neetcode 150
 * Neetcode Topic: 1-D DP
 */

int rob(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    if (nums.size() == 2)
    {
        return max(nums[0], nums[1]);
    }

    vector<int> table1(nums.size() - 1, -1);
    vector<int> table2(nums.size() - 1, -1);

    table1[0] = nums[0];
    table1[1] = max(nums[0], nums[1]);

    table2[0] = nums[1];
    table2[1] = max(nums[1], nums[2]);

    for (int i = 2; i < nums.size() - 1; i++)
    {
        table1[i] = max(nums[i] + table1[i - 2], table1[i - 1]);
        table2[i] = max(nums[i + 1] + table2[i - 2], table2[i - 1]);
    }

    int table1_max = max(table1[table1.size() - 1], table1[table1.size() - 2]);
    int table2_max = max(table2[table2.size() - 1], table2[table2.size() - 2]);

    return max(table1_max, table2_max);
}