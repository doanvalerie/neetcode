"""
Author: Valerie Doan
Date: November 8, 2024
Problem: Partition Equal Subset Sum
Level: Medium
Neetcode Course: Advanced Algorithms
Neetcode Topic: 0/1 Knapsack
"""


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 == 1:
            return False
        target_sum = total // 2

        rows = len(nums) + 1
        cols = target_sum + 1
        dp = [[False for i in range(cols)] for j in range(rows)]

        for i in range(1, rows):
            for j in range(1, cols):
                dp[i][j] = dp[i - 1][j]

                if j == nums[i - 1]:
                    dp[i][j] = True
                elif j - nums[i - 1] > 0:
                    dp[i][j] = dp[i][j] or dp[i - 1][j - nums[i - 1]]

            if dp[i][cols - 1]:
                return True

        return False
