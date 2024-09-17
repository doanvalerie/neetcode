#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: September 8, 2024
 * Problem: Contains Duplicate II
 * Level: Easy
 * Neetcode Course: Advanced Algorithms
 * Neetcode Topic: Sliding Window Fixed Size
 */

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    int left = 0;
    unordered_set<int> s;

    for (int right = 0; right < nums.size(); right++)
    {
        if (right - left > k)
        {
            s.erase(nums[left]);
            left++;
        }

        if (s.find(nums[right]) != s.end())
        {
            return true;
        }

        s.insert(nums[right]);
    }

    return false;
}

bool containsNearbyDuplicate_v2(vector<int> &nums, int k)
{
    unordered_map<int, int> pos_map;
    int l = 0;

    for (int r = 0; r < nums.size(); r++)
    {
        while (r - l > k)
        {
            pos_map.erase(nums[l]);
            l++;
        }

        if (pos_map.find(nums[r]) != pos_map.end() && r - pos_map[nums[r]] <= k)
        {
            return true;
        }

        pos_map[nums[r]] = r;
    }

    return false;
}

/* Brute Force */
bool containsNearbyDuplicate_v3(vector<int> &nums, int k)
{
    for (int i = 0; i < nums.size(); i++)
    {
        unordered_set<int> s;

        for (int j = i; j <= i + k && j < nums.size(); j++)
        {
            if (s.find(nums[j]) != s.end())
            {
                return true;
            }

            s.insert(nums[j]);
        }
    }

    return false;
}
