#include <string>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: November 12, 2024
 * Problem: 2904. Shortest and Lexicographically Smallest Beautiful String
 * Level: Medium
 * Topics: String, Sliding Window
 */

string shortestBeautifulSubstring(string s, int k)
{
    string res = "";
    int count = 0;
    int L = 0;

    for (int R = 0; R < s.size(); R++)
    {
        while (L < s.size() && s[L] != '1')
        {
            L++;
        }

        if (L > R)
        {
            L = R;
        }

        if (s[R] == '1')
        {
            count++;
        }

        if (count == k)
        {
            int length = R - L + 1;
            string sub = s.substr(L, length);

            if (length == res.size() && sub < res || length < res.size() || res.empty())
            {
                res = sub;
            }

            L++;
            count--;
        }
    }

    return res;
}