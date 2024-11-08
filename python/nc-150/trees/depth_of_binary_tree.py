"""
Author: Valerie Doan
Date: November 7, 2024
Problem: Maximum Depth of Binary Tree
Level: Easy
Neetcode Course: Neetcode 150
Neetcode Topic: Trees
"""


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        left = self.maxDepth(root.left) + 1
        right = self.maxDepth(root.right) + 1
        return max(left, right)
