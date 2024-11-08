/*
 * Author: Valerie Doan
 * Date: November 1, 2024
 * Problem: Diameter of Binary Tree
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

/* -------------------- SOLUTION 1 -------------------- */

int helper(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    return 1 + max(helper(root->left), helper(root->right));
}

int diameterOfBinaryTree(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    int opt1 = diameterOfBinaryTree(root->left);
    int opt2 = diameterOfBinaryTree(root->right);
    int max_exc = max(opt1, opt2);

    return max(max_exc, helper(root->left) + helper(root->right));
}

/* -------------------- SOLUTION 2 -------------------- */

int init(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        root->val = 0;
        return 0;
    }

    root->val = 1 + max(init(root->left), init(root->right));
    return root->val;
}

int dfs(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    int left = root->left ? root->left->val + 1 : 0;
    int right = root->right ? root->right->val + 1 : 0;
    int opt1 = left + right;
    int opt2 = max(dfs(root->left), dfs(root->right));

    return max(opt1, opt2);
}

int diameterOfBinaryTree(TreeNode *root)
{
    init(root);
    return dfs(root);
}

/* -------------------- SOLUTION 3 -------------------- */

int dfs(TreeNode *root, int &res)
{
    if (!root)
    {
        return 0;
    }

    int left = dfs(root->left, res);
    int right = dfs(root->right, res);

    int opt1 = left + right;
    res = max(res, opt1);

    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode *root)
{
    int res = 0;
    dfs(root, res);
    return res;
}
