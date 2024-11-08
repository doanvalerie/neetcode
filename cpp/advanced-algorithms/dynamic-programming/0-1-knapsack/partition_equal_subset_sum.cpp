#include <numeric>
#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: November 8, 2024
 * Problem: Partition Equal Subset Sum
 * Level: Medium
 * Neetcode Course: Advanced Algorithms
 * Neetcode Topic: 0/1 Knapsack
 */

bool canPartition(vector<int> &nums)
{
    int target_sum = accumulate(nums.begin(), nums.end(), 0);
    if (target_sum % 2 == 1)
    {
        return false;
    }
    int n = nums.size() + 1;
    int m = target_sum / 2 + 1;
    bool dp[n][m];
    memset(dp, false, n * m * sizeof(bool));

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (nums[i - 1] == j)
            {
                dp[i][j] = true;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
                if (j - nums[i - 1] > 0)
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        if (dp[i][m - 1])
        {
            return true;
        }
    }
    return false;
}