#include <algorithm>
#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 21, 2024
 * Problem: Construct Binary Tree from Preorder and Inorder Traversal
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

TreeNode *_buildTree(vector<int> &preorder, vector<int> &inorder, int &p_index, int left, int right)
{
    if (left > right)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[p_index++]);
    int split_index = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();

    root->left = _buildTree(preorder, inorder, p_index, left, split_index - 1);
    root->right = _buildTree(preorder, inorder, p_index, split_index + 1, right);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int p_index = 0;
    return _buildTree(preorder, inorder, p_index, 0, inorder.size() - 1);
}

/* ------------------------------------------------ */

TreeNode *_buildTree(vector<int> &preorder, vector<int> &inorder, int &p_index)
{
    if (inorder.size() == 0)
    {
        return nullptr;
    }

    vector<int> left;
    vector<int> right;
    TreeNode *root = new TreeNode(preorder[p_index++]);
    int split_index = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();

    for (int i = 0; i < split_index; i++)
    {
        left.push_back(inorder[i]);
    }

    for (int i = split_index + 1; i < inorder.size(); i++)
    {
        right.push_back(inorder[i]);
    }

    root->left = _buildTree(preorder, left, p_index);
    root->right = _buildTree(preorder, right, p_index);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int p_index = 0;
    return _buildTree(preorder, inorder, p_index);
}
