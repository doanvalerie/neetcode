#include <string>
#include <unordered_set>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: September 24, 2024
 * Problem: Longest Substring Without Repeating Characters
 * Level: Medium
 * Neetcode Course: Advanced Algorithms
 * Neetcode Topic: Sliding Window Variable Size
 */

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> char_set;
    int max_length = 0;
    int L = 0;

    for (int R = 0; R < s.size(); R++)
    {
        while (char_set.find(s[R]) != char_set.end())
        {
            char_set.erase(s[L]);
            L++;
        }

        char_set.insert(s[R]);
        max_length = max(R - L + 1, max_length);
    }

    return max_length;
}