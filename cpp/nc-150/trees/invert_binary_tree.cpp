/*
 * Author: Valerie Doan
 * Date: October 25, 2024
 * Problem: Invert Binary Tree
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

TreeNode *invertTree(TreeNode *root)
{
    if (!root)
    {
        return root;
    }

    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}
