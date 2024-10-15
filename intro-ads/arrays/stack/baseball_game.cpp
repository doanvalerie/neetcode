#include <vector>
#include <stack>
#include <string>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: July 5, 2024
 * Problem: Baseball Game
 * Level: Easy
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Stacks
 */

int calPoints(vector<string> &operations)
{
    vector<int> scores;
    int length = 0;

    for (string op : operations)
    {
        int n = scores.size();

        if (op == "+")
        {
            scores.push_back(scores[n - 1] + scores[n - 2]);
        }
        else if (op == "D")
        {
            scores.push_back(2 * scores[n - 1]);
        }
        else if (op == "C")
        {
            scores.pop_back();
        }
        else
        {
            scores.push_back(stoi(op));
        }
    }

    int total = 0;
    for (int val : scores)
    {
        total += val;
    }

    return total;
}

int calPoints_v2(vector<string> &operations)
{
    stack<int> scores;
    int total = 0;

    for (string op : operations)
    {
        int n = scores.size();
        int new_score = 0;

        if (op == "+")
        {
            int top = scores.top();
            scores.pop();
            int second_top = scores.top();
            scores.push(top);

            new_score = top + second_top;
            scores.push(new_score);
        }
        else if (op == "D")
        {
            new_score = 2 * scores.top();
            scores.push(new_score);
        }
        else if (op == "C")
        {
            total -= scores.top();
            scores.pop();
        }
        else
        {
            new_score = stoi(op);
            scores.push(new_score);
        }

        total += new_score;
    }

    return total;
}
