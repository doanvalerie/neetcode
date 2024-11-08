#include <vector>

using namespace std;

bool helper(vector<int> &nums, int left_sum, int right_sum, int i)
{
    if (i == nums.size())
    {
        return left_sum == right_sum;
    }

    int opt1 = helper(nums, left_sum + nums[i], right_sum, i + 1);
    int opt2 = helper(nums, left_sum, right_sum + nums[i], i + 1);
    return opt1 || opt2;
}

bool canPartition(vector<int> &nums)
{
    return helper(nums, 0, 0, 0);
}