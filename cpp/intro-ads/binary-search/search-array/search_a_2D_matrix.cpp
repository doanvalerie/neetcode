#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 29, 2024
 * Problem: Search a 2D Matrix
 * Level: Medium
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Search Array
 */

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int T = 0;
    int B = m - 1;
    int L = 0;
    int R = n - 1;

    int y_mid;

    while (T <= B)
    {
        y_mid = (T + B) / 2;

        if (target >= matrix[y_mid][0] && target <= matrix[y_mid][n - 1])
        {
            break;
        }
        else if (target < matrix[y_mid][0])
        {
            B = y_mid - 1;
        }
        else if (target > matrix[y_mid][0])
        {
            T = y_mid + 1;
        }
    }

    if (T > B)
    {
        return false;
    }

    while (L <= R)
    {
        int x_mid = (L + R) / 2;

        if (target < matrix[y_mid][x_mid])
        {
            R = x_mid - 1;
        }
        else if (target > matrix[y_mid][x_mid])
        {
            L = x_mid + 1;
        }
        else
        {
            return true;
        }
    }

    return false;
}