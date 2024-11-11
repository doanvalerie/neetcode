"""
Author: Valerie Doan
Date: November 10, 2024
Problem: Target Sum
Level: Medium
Neetcode Course: Advanced Algorithms
Neetcode Topic: 0/1 Knapsack
"""


class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        bound = sum(nums)

        if target > bound:
            return 0

        cols = bound * 2 + 1
        dp = [[0 for i in range(cols)] for j in range(len(nums))]

        if len(nums) > 0:
            dp[0][bound + nums[0]] += 1
            dp[0][bound - nums[0]] += 1

        for i in range(1, len(nums)):
            for j in range(cols):
                if dp[i - 1][j] != 0:
                    dp[i][j - nums[i]] += dp[i - 1][j]
                    dp[i][j + nums[i]] += dp[i - 1][j]

        return dp[len(nums) - 1][bound + target]
