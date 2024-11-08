#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: September 8, 2024
 * Problem: Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 * Level: Medium
 * Neetcode Course: Advanced Algorithms
 * Neetcode Topic: Sliding Window Fixed Size
 */

int numOfSubarrays(vector<int> &arr, int k, int threshold)
{
    int result = 0;
    int l = 0;
    int curr_avg = 0;
    int threshold_k = threshold * k;

    for (int r = 0; r < arr.size(); r++)
    {
        if (r - l == k)
        {
            curr_avg -= arr[l];
            l++;
        }

        curr_avg += arr[r];

        if (r >= k - 1 && curr_avg >= threshold_k)
        {
            result++;
        }
    }

    return result;
}