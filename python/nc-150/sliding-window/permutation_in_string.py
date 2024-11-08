"""
Author: Valerie Doan
Date: November 7, 2024
Problem: Permutation in String
Level: Medium
Neetcode Course: Neetcode 150
Neetcode Topic: Sliding Window
"""


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        dictionary = {char: 0 for char in set(s1 + s2)}

        for char in s1:
            dictionary[char] += 1

        L = 0
        for R in range(len(s2)):
            dictionary[s2[R]] -= 1

            while dictionary[s2[R]] < 0:
                dictionary[s2[L]] += 1
                L += 1

            if R - L + 1 == len(s1):
                return True

        return False
