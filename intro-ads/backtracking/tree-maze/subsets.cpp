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

void backtrack(vector<int> &nums, vector<int> curr_set, vector<vector<int>> &res)
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
    backtrack(nums, {}, res);
    return res;
}