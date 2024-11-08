#include <string>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 13, 2024
 * Problem: Palindromic Substrings
 * Level: Medium
 * Neetcode Course: Advanced Algorithms
 * Neetcode Topic: Palindromes
 */

int countSubstrings(string s)
{
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        count++;

        int j = 1;
        while (i - j >= 0 && i + j < s.size())
        {
            if (s[i - j] == s[i + j])
            {
                count++;
            }
            else
            {
                break;
            }
            j++;
        }

        j = 0;
        while (i - j >= 0 && i + j + 1 < s.size())
        {
            if (s[i - j] == s[i + j + 1])
            {
                count++;
            }
            else
            {
                break;
            }
            j++;
        }
    }

    return count;
}
