#include <set>
#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 22, 2024
 * Problem: Combination Sum
 * Level: Medium
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Tree Maze
 */

/* fixed! */
void backtrack(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &nums, int sum, int index)
{
    if (sum == target)
    {
        res.push_back(nums);
        return;
    }
    if (sum > target)
    {
        return;
    }

    for (int i = index; i < candidates.size(); i++)
    {
        nums.push_back(candidates[i]);
        backtrack(candidates, target, res, nums, sum + candidates[i], i);
        nums.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> nums;
    backtrack(candidates, target, res, nums, 0, 0);
    return res;
}

/* beats 5.02% runtime... :3 */
void backtrack_v2(vector<int> &candidates, int target, set<multiset<int>> &combos, vector<int> &nums, int sum)
{
    if (sum == target)
    {
        combos.insert(multiset<int>(nums.begin(), nums.end()));
        return;
    }
    if (sum > target)
    {
        return;
    }

    for (int i = 0; i < candidates.size(); i++)
    {
        nums.push_back(candidates[i]);
        backtrack_v2(candidates, target, combos, nums, sum + candidates[i]);
        nums.pop_back();
    }
}

vector<vector<int>> combinationSum_v2(vector<int> &candidates, int target)
{
    set<multiset<int>> combos;
    vector<vector<int>> res;
    vector<int> nums;
    backtrack_v2(candidates, target, combos, nums, 0);

    for (const multiset<int> &combo : combos)
    {
        res.push_back(vector<int>(combo.begin(), combo.end()));
    }

    return res;
}