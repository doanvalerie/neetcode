#include <string>
#include <unordered_map>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 6, 2024
 * Problem: Longest Repeating Character Replacement
 * Level: Medium
 * Neetcode Course: Advanced Algorithms
 * Neetcode Topic: Sliding Window Variable Size
 */

int characterReplacement(string s, int k)
{
    unordered_map<char, int> char_freq;
    int max_char_freq = 0;
    int result = 0;
    int L = 0;

    for (int R = 0; R < s.size(); R++)
    {
        max_char_freq = max(max_char_freq, ++char_freq[s[R]]);
        int length = R - L + 1;

        while (length - max_char_freq > k)
        {
            char_freq[s[L++]]--;
            length = R - L + 1;

            for (auto const &[key, value] : char_freq)
            {
                if (value > max_char_freq)
                {
                    max_char_freq = value;
                }
            }
        }

        result = max(result, length);
    }

    return result;
}

/* -------------------- REVIEW -------------------- */

/*
 * Author: Valerie Doan
 * Date: October 30, 2024
 * Problem: Longest Repeating Character Replacement
 * Level: Medium
 * Neetcode Course: Advanced Algorithms
 * Neetcode Topic: Sliding Window Variable Size
 */

int characterReplacement(string s, int k)
{
    unordered_map<char, int> char_freq;
    int highest_freq = 0;
    int res = 0;
    int L = 0;

    for (int R = 0; R < s.size(); R++)
    {
        highest_freq = max(highest_freq, ++char_freq[s[R]]);

        if (R - L + 1 - highest_freq <= k)
        {
            res = max(res, R - L + 1);
        }
        else
        {
            char_freq[s[L++]]--;
        }
    }

    return res;
}

int characterReplacement_v2(string s, int k)
{
    unordered_map<char, int> char_freq;
    int highest_freq = 0;
    int res = 0;
    int L = 0;

    for (int R = 0; R < s.size(); R++)
    {
        if (++char_freq[s[R]] > highest_freq)
        {
            highest_freq = char_freq[s[R]];
        }
        if (R - L + 1 - highest_freq <= k)
        {
            res = max(res, R - L + 1);
        }

        while (R - L + 1 - highest_freq > k)
        {
            char_freq[s[L++]]--;
            for (const auto &[key, value] : char_freq)
            {
                highest_freq = max(highest_freq, value);
            }
        }
    }

    return res;
}