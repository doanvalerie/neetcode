#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 27, 2024
 * Problem: Design Binary Search Tree
 * Level: Medium
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: BST Sets and Maps
 */

class TreeNode
{
public:
    TreeNode(int key, int value) : key(key), value(value) {}
    int key;
    int value;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

class TreeMap
{
public:
    TreeMap() {}

    void insert(int key, int val)
    {
        root = insertHelper(key, val, root);
    }

    int get(int key)
    {
        TreeNode *curr = root;
        while (curr)
        {
            if (key < curr->key)
            {
                curr = curr->left;
            }
            else if (key > curr->key)
            {
                curr = curr->right;
            }
            else
            {
                return curr->value;
            }
        }
        return -1;
    }

    int getMin()
    {
        if (!root)
        {
            return -1;
        }
        TreeNode *curr = root;
        while (curr->left)
        {
            curr = curr->left;
        }
        return curr->value;
    }

    int getMax()
    {
        if (!root)
        {
            return -1;
        }
        TreeNode *curr = root;
        while (curr->right)
        {
            curr = curr->right;
        }
        return curr->value;
    }

    void remove(int key)
    {
        root = removeHelper(key, root);
    }

    vector<int> getInorderKeys()
    {
        vector<int> keys;
        getInorderKeysHelper(keys, root);
        return keys;
    }

private:
    TreeNode *root = nullptr;

    TreeNode *getMinNode(TreeNode *root)
    {
        if (!root->left)
        {
            return root;
        }
        return getMinNode(root->left);
    }

    TreeNode *insertHelper(int key, int val, TreeNode *root)
    {
        if (!root)
        {
            return new TreeNode(key, val);
        }
        if (key < root->key)
        {
            root->left = insertHelper(key, val, root->left);
        }
        else if (key > root->key)
        {
            root->right = insertHelper(key, val, root->right);
        }
        else
        {
            root->key = key;
            root->value = val;
        }
        return root;
    }

    TreeNode *removeHelper(int key, TreeNode *root)
    {
        if (!root)
        {
            return nullptr;
        }
        if (key < root->key)
        {
            root->left = removeHelper(key, root->left);
        }
        else if (key > root->key)
        {
            root->right = removeHelper(key, root->right);
        }
        else
        {
            if (!root->left)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            if (!root->right)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            TreeNode *min = getMinNode(root->right);
            root->key = min->key;
            root->value = min->value;
            root->right = removeHelper(min->key, root->right);
        }
        return root;
    }

    void getInorderKeysHelper(vector<int> &keys, TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        getInorderKeysHelper(keys, root->left);
        keys.push_back(root->key);
        getInorderKeysHelper(keys, root->right);
    }
};
