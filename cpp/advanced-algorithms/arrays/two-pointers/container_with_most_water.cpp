#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: September 30, 2024
 * Problem: Container With Most Water
 * Level: Medium
 * Neetcode Course: Advanced Algorithms
 * Neetcode Topic: Two Pointers
 */

int maxArea(vector<int> &height)
{
    int l = 0;
    int r = height.size() - 1;
    int max_area = 0;

    while (l < r)
    {
        int min_height = min(height[l], height[r]);
        int curr_area = min_height * (r - l);
        max_area = max(max_area, curr_area);

        if (height[l] < height[r])
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    return max_area;
}