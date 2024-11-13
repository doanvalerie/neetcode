#include <vector>
#include <string>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: November 12, 2024
 * Problem: 38. Count and Say
 * Level: Medium
 * Topics: String
 */

string countAndSay(int n)
{
    vector<string> RLE = {"1"};

    for (int i = 1; i < n; i++)
    {
        string str = RLE[i - 1];
        string compressed = "";

        char curr_ch = str[0];
        int count = 0;

        for (char ch : str)
        {
            if (ch == curr_ch)
            {
                count++;
            }
            else
            {
                compressed += to_string(count) + curr_ch;
                curr_ch = ch;
                count = 1;
            }
        }

        compressed += to_string(count) + curr_ch;
        RLE.push_back(compressed);
    }

    return RLE[n - 1];
}