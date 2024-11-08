#include <queue>
#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 25, 2024
 * Problem: Binary Tree Right Side View
 * Level: Medium
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Breadth-First Search
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

vector<int> rightSideView(TreeNode *root)
{
    vector<int> res;
    queue<TreeNode *> q;

    if (root)
    {
        q.push(root);
    }

    while (!q.empty())
    {
        int size = q.size();
        res.push_back(q.front()->val);
        
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->right)
            {
                q.push(node->right);
            }
            if (node->left)
            {
                q.push(node->left);
            }
        }
    }

    return res;
}