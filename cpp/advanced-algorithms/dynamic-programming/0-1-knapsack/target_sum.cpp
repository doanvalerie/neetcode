#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: November 10, 2024
 * Problem: Target Sum
 * Level: Medium
 * Neetcode Course: Advanced Algorithms
 * Neetcode Topic: 0/1 Knapsack
 */

/* -------------------- SOLUTION 1 -------------------- */

void helper(vector<int> &nums, int target, int index, int &res, int sum)
{
    if (index == nums.size())
    {
        if (sum == target)
        {
            res++;
        }
        return;
    }

    helper(nums, target, index + 1, res, sum - nums[index]);
    helper(nums, target, index + 1, res, sum + nums[index]);
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int res = 0;
    helper(nums, target, 0, res, 0);
    return res;
}

/* -------------------- SOLUTION 2 -------------------- */

int findTargetSumWays(vector<int> &nums, int target)
{
    unordered_map<int, unordered_map<int, int>> tab;

    if (nums.size() > 0)
    {
        tab[0][nums[0]]++;
        tab[0][0 - nums[0]]++;
    }

    for (int i = 1; i < nums.size(); i++)
    {
        unordered_map<int, int> target_freq = tab[i - 1];

        for (auto &[key, value] : target_freq)
        {
            tab[i][key - nums[i]] += value;
            tab[i][key + nums[i]] += value;
        }
    }

    return tab[nums.size() - 1][target];
}

/* -------------------- SOLUTION 3 -------------------- */

int findTargetSumWays(vector<int> &nums, int target)
{
    int bound = accumulate(nums.begin(), nums.end(), 0);

    if (abs(target) > bound)
    {
        return 0;
    }

    vector<vector<int>> tab(nums.size(), vector<int>(bound * 2 + 1, 0));

    if (nums.size() > 0)
    {
        tab[0][bound + nums[0]] += 1;
        tab[0][bound - nums[0]] += 1;
    }

    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 0; j < bound * 2 + 1; j++)
        {
            if (tab[i - 1][j] != 0)
            {
                tab[i][j + nums[i]] += tab[i - 1][j];
                tab[i][j - nums[i]] += tab[i - 1][j];
            }
        }
    }

    return tab[nums.size() - 1][bound + target];
}