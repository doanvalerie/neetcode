/*
 * Author: Valerie Doan
 * Date: October 19, 2024
 * Problem: Delete Node in a BST
 * Level: Medium
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: BST Insert and Remove
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

TreeNode *getMinNode(TreeNode *root)
{
    TreeNode *min_node = root;

    while (min_node != nullptr && min_node->left != nullptr)
    {
        min_node = min_node->left;
    }

    return min_node;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (key > root->val)
    {
        root->right = deleteNode(root->right, key);
    }
    else if (key < root->val)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            return root->right;
        }
        else if (root->right == nullptr)
        {
            return root->left;
        }
        else
        {
            TreeNode *min_node = getMinNode(root->right);
            root->val = min_node->val;
            root->right = deleteNode(root->right, min_node->val);
        }
    }

    return root;
}
