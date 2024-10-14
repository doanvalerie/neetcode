#include <vector>
#include <unordered_map>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 13, 2024
 * Problem: Longest Consecutive Sequence
 * Level: Medium
 * Neetcode Course: Neetcode 150
 * Neetcode Topic: Arrays & Hashing
 */

int longestConsecutive(vector<int> &nums)
{
    unordered_map<int, pair<int, int>> m;
    int length = 0;

    for (int num : nums)
    {
        if (m.find(num) != m.end())
        {
            continue;
        }

        int low = num;
        int high = num;

        if (m.find(num - 1) != m.end())
        {
            pair<int, int> left = m[num - 1];
            low = left.first;
        }

        if (m.find(num + 1) != m.end())
        {
            pair<int, int> right = m[num + 1];
            high = right.second;
        }

        m[low].second = high;
        m[high].first = low;

        m[num] = {low, high};
        length = max(high - low + 1, length);
    }

    return length;
}