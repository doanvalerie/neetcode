"""
Author: Valerie Doan
Date: November 11, 2024
Problem: Contains Duplicate II
Level: Easy
Neetcode Course: Advanced Algorithms
Neetcode Topic: Sliding Window Fixed Size
"""


class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        visited = set()
        L = 0

        for R in range(len(nums)):
            if R - L > k:
                visited.remove(nums[L])
                L += 1

            if nums[R] in visited:
                return True

            visited.add(nums[R])

        return False
