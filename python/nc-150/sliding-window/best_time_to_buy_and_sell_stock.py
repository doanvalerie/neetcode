"""
Author: Valerie Doan
Date: November 11, 2024
Problem: Best Time to Buy and Sell Stock
Level: Easy
Neetcode Course: Neetcode 150
Neetcode Topic: Sliding Window
"""


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = L = 0

        for R in range(len(prices)):
            while prices[R] - prices[L] < 0:
                L += 1

            max_profit = max(prices[R] - prices[L], max_profit)

        return max_profit
