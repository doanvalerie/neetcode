/*
 * Author: Valerie Doan
 * Date: October 21, 2024
 * Problem: Path Sum
 * Level: Easy
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Tree Maze
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

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (!root)
    {
        return false;
    }

    targetSum -= root->val;

    if (!root->left && !root->right && targetSum == 0)
    {
        return true;
    }

    return (hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum));
}
