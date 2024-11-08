/*
 * Author: Valerie Doan
 * Date: October 14, 2024
 * Problem: Search in a Binary Search Tree
 * Level: Easy
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Binary Search Tree
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

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (val < root->val)
        {
            return searchBST(root->left, val);
        }
        if (val > root->val)
        {
            return searchBST(root->right, val);
        }
        return root;
    }
};