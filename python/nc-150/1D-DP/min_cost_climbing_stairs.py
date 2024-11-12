"""
Author: Valerie Doan
Date: November 11, 2024
Problem: Min Cost Climbing Stairs
Level: Easy
Neetcode Course: Neetcode 150
Neetcode Topic: 1-D DP
"""


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = []

        if len(cost) == 1:
            return cost[0]

        dp.extend([cost[0], cost[1]])

        for i in range(2, len(cost)):
            dp.append(min(cost[i] + dp[i - 1], cost[i] + dp[i - 2]))

        return min(dp[len(dp) - 1], dp[len(dp) - 2])
