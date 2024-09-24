#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: September 14, 2024
 * Problem: Minimum Size Subarray Sum
 * Level: Medium
 * Neetcode Course: Advanced Algorithms
 * Neetcode Topic: Sliding Window Variable Size
 */

int minSubArrayLen(int target, vector<int> &nums)
{
    int min_length = 0;
    int curr_sum = 0;
    int left = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        curr_sum += nums[right];

        while (curr_sum >= target)
        {
            int curr_length = right - left + 1;
            min_length = min_length == 0 ? curr_length : min(min_length, curr_length);
            curr_sum -= nums[left++];
        }
    }

    return min_length;
}