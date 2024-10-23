#include <set>
#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 22, 2024
 * Problem: Subsets
 * Level: Medium
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Tree Maze
 */

/* Pass by reference for faster runtime */
void backtrack(vector<int> &nums, vector<int> &curr_set, vector<vector<int>> &res)
{
    if (nums.size() == 0)
    {
        res.push_back(curr_set);
        return;
    }

    vector<int> remainder(nums.begin() + 1, nums.end());
    curr_set.push_back(nums[0]);
    backtrack(remainder, curr_set, res);
    curr_set.pop_back();
    backtrack(remainder, curr_set, res);
}

void backtrack_v2(vector<int> &nums, vector<int> curr_set, vector<vector<int>> &res)
{
    if (nums.size() == 0)
    {
        res.push_back(curr_set);
        return;
    }

    vector<int> remainder(nums.begin() + 1, nums.end());
    backtrack(remainder, curr_set, res);
    curr_set.push_back(nums[0]);
    backtrack(remainder, curr_set, res);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> curr_set;
    backtrack(nums, curr_set, res);
    return res;
}