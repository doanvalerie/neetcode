#include <stack>
#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 20, 2024
 * Problem: Binary Tree Inorder Traversal
 * Level: Easy
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

vector<int> inorderTraversal_v2(TreeNode *root)
{
    TreeNode *curr = root;
    vector<int> visited;
    stack<TreeNode *> st;

    while (!st.empty() || curr != nullptr)
    {
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        TreeNode *next = st.top();
        st.pop();
        visited.push_back(next->val);
        curr = next->right;
    }

    return visited;
}

void _inorderTraversal(TreeNode *root, vector<int> &visited)
{
    if (root == nullptr)
    {
        return;
    }
    _inorderTraversal(root->left, visited);
    visited.push_back(root->val);
    _inorderTraversal(root->right, visited);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> visited;
    _inorderTraversal(root, visited);
    return visited;
}
