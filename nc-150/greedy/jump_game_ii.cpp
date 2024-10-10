#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 9, 2024
 * Problem: Jump Game II
 * Level: Medium
 * Neetcode Course: Neetcode 150
 * Neetcode Topic: Greedy
 */

int jump(vector<int> &nums)
{
    int count = 0;
    int position = 0;

    while (position < nums.size() - 1)
    {
        int new_position = position + 1;
        int max_dest = -1;

        for (int i = position + 1; i < position + 1 + nums[position] && i < nums.size(); i++)
        {
            int jump_dest = nums[i] + i >= nums.size() ? nums.size() - 1 : nums[i] + i;

            if (jump_dest >= max_dest)
            {
                max_dest = jump_dest;
                new_position = i;
            }
        }

        position = new_position;
        count++;
    }

    return count;
}
