#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 4, 2024
 * Problem: Range Sum Query - Immutable
 * Level: Easy
 * Neetcode Course: Advanced Algorithms
 * Neetcode Topic: Prefix Sums
 */

class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        int total = 0;

        for (int num : nums)
        {
            total += num;
            prefix_sum.push_back(total);
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
        {
            return prefix_sum[right];
        }
        return prefix_sum[right] - prefix_sum[left - 1];
    }

private:
    vector<int> prefix_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */