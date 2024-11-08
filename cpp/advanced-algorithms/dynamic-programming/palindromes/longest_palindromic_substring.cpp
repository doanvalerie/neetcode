#include <string>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 18, 2024
 * Problem: Longest Palindromic Substring
 * Level: Medium
 * Neetcode Course: Advanced Algorithms
 * Neetcode Topic: Palindromes
 */

void helper(string s, string &result, int L, int R)
{
    for (int j = 0; L - j >= 0 && R + j < s.size(); j++)
    {
        int length = R - L + 2 * j + 1;

        if (s[L - j] == s[R + j])
        {
            if (length >= result.size())
            {
                result = s.substr(L - j, length);
            }
        }
        else
        {
            break;
        }
    }
}

string longestPalindrome(string s)
{
    string result = "";

    for (int i = 0; i < s.size(); i++)
    {
        helper(s, result, i, i);
        helper(s, result, i, i + 1);
    }

    return result;
}
