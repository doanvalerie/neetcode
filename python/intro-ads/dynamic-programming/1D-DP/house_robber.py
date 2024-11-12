"""
Author: Valerie Doan
Date: November 11, 2024
Problem: House Robber
Level: Medium
Neetcode Course: Algorithms and Data Structures for Beginners
Neetcode Topic: 1-Dimension DP
"""


class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [0, nums[0]]

        for i in range(1, len(nums)):
            dp.append(max(dp[i], nums[i] + dp[i - 1]))

        return dp[len(dp) - 1]
