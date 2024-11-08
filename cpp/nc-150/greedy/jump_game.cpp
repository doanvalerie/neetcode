#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 7, 2024
 * Problem: Jump Game
 * Level: Medium
 * Neetcode Course: Neetcode 150
 * Neetcode Topic: Greedy
 */

bool canJump(vector<int> &nums)
{
    int i = 0;
    int num_jumps = nums[0];

    while (i < nums.size() - 1)
    {
        if (num_jumps == 0)
        {
            return false;
        }

        i++;
        num_jumps--;

        if (nums[i] > num_jumps)
        {
            num_jumps = nums[i];
        }
    }

    return true;
}