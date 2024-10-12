#include <string>
#include <unordered_map>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 11, 2024
 * Problem: Permutation in String
 * Level: Medium
 * Neetcode Course: Neetcode 150
 * Neetcode Topic: Sliding Window
 */

bool checkInclusion(string s1, string s2)
{
    unordered_map<char, int> char_freq;

    for (char ch : s1)
    {
        char_freq[ch]++;
    }

    int L = 0;
    int R = 0;

    while (R < s2.size())
    {
        char_freq[s2[R]]--;

        while (char_freq[s2[R]] < 0)
        {
            char_freq[s2[L]]++;
            L++;
        }

        if (char_freq[s2[R]] >= 0)
        {
            if (R - L + 1 == s1.size())
            {
                return true;
            }
        }
        R++;
    }

    return false;
}