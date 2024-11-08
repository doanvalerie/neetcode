/*
 * Author: Valerie Doan
 * Date: October 20, 2024
 * Problem: Kth Smallest Element in a BST
 * Level: Medium
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Depth-First Search
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

/* O(n) */
void inorderTraversal(TreeNode *root, int &res, int k, int &i)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left, res, k, i);
    if (++i == k)
    {
        res = root->val;
        return;
    }
    inorderTraversal(root->right, res, k, i);
}

int kthSmallest(TreeNode *root, int k)
{
    int res = -1;
    int i = 0;
    inorderTraversal(root, res, k, i);
    return res;
}
