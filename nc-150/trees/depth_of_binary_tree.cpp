/*
 * Author: Valerie Doan
 * Date: October 27, 2024
 * Problem: Maximum Depth of Binary Tree
 * Level: Easy
 * Neetcode Course: Neetcode 150
 * Neetcode Topic: Trees
 */

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

void helper(TreeNode *root, int &res, int height)
{
    if (!root)
    {
        return;
    }
    res = max(res, ++height);
    helper(root->left, res, height);
    helper(root->right, res, height);
}

int maxDepth(TreeNode *root)
{
    int res = 0;
    helper(root, res, 0);
    return res;
}