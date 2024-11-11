"""
Author: Valerie Doan
Date: November 11, 2024
Problem: Coin Change
Level: Medium
Neetcode Course: Neetcode 150
Neetcode Topic: 1-D DP
"""


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [-1 for i in range(amount + 1)]
        dp[0] = 0

        for amt in range(len(dp)):
            for coin in coins:
                if amt - coin < 0 or dp[amt - coin] == -1:
                    continue

                if dp[amt] == -1:
                    dp[amt] = 1 + dp[amt - coin]

                dp[amt] = min(dp[amt], 1 + dp[amt - coin])

        return dp[amount]
