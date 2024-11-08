"""
Author: Valerie Doan
Date: November 7, 2024
Problem: Find Pivot Index
Level: Easy
Neetcode Course: Advanced Algorithms
Neetcode Topic: Prefix Sum
"""


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        prefix = [0] * len(nums)
        postfix = [0] * len(nums)

        for i in range(len(nums)):
            if i == 0:
                prefix[i] = nums[i]
            else:
                prefix[i] = prefix[i - 1] + nums[i]

        for i in range(len(nums) - 1, -1, -1):
            if i == len(nums) - 1:
                postfix[i] = nums[i]
            else:
                postfix[i] = postfix[i + 1] + nums[i]

        for i in range(len(nums)):
            if prefix[i] == postfix[i]:
                return i

        return -1
