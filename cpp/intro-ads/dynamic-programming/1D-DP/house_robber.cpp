#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 18, 2024
 * Problem: House Robber
 * Level: Medium
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: 1-Dimension DP
 */

/* Top-down */
int _rob_v3(const vector<int> &nums, vector<int> &cache, int i)
{
    if (i < 0)
    {
        return 0;
    }
    if (cache[i] != -1)
    {
        return cache[i];
    }
    cache[i] = max(nums[i] + _rob_v3(nums, cache, i - 2), _rob_v3(nums, cache, i - 1));
    return cache[i];
}

int rob_v3(vector<int> &nums)
{
    vector<int> cache(nums.size(), -1);
    int opt1 = _rob_v3(nums, cache, nums.size() - 1);
    int opt2 = _rob_v3(nums, cache, nums.size() - 2);
    return max(opt1, opt2);
}

/* Bottom-up */
int rob_v2(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }

    vector<int> table;
    table.push_back(nums[0]);
    table.push_back(max(nums[0], nums[1]));

    for (int i = 2; i < nums.size(); i++)
    {
        table.push_back(max(nums[i] + table[i - 2], table[i - 1]));
    }

    return max(table[table.size() - 1], table[table.size() - 2]);
}

/* Bottom-up */
int rob(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }

    vector<int> table;
    table.push_back(nums[0]);
    table.push_back(nums[1]);

    if (nums.size() > 2)
    {
        table.push_back(nums[0] + nums[2]);
    }

    for (int i = 3; i < nums.size(); i++)
    {
        table.push_back(nums[i] + max(table[i - 2], table[i - 3]));
    }

    return max(table[table.size() - 1], table[table.size() - 2]);
}