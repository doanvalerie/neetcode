#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: July 5, 2024
 * Problem: Valid Parentheses
 * Level: Easy
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Stacks
 */

bool isValid(string s)
{
    stack<char> st;
    unordered_map<char, char> map = {
        {'}', '{'},
        {']', '['},
        {')', '('},
    };

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];

        switch (ch)
        {
        case '(':
        case '[':
        case '{':
            st.push(ch);
            break;
        default:
            if (!st.empty() && map[ch] == st.top())
            {
                st.pop();
            }
            else
            {
                return false;
            }
            break;
        }
    }

    return st.empty();
}
