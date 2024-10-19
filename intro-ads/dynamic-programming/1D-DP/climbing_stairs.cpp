#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 18, 2024
 * Problem: Climbing Stairs
 * Level: Easy
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: 1-Dimension DP
 */

/* Top-down */
int _climbStairs_v2(int n, vector<int> &cache)
{
    if (cache[n] != -1)
    {
        return cache[n];
    }
    if (n == 0)
    {
        cache[0] = 1;
        return cache[0];
    }
    if (n == 1)
    {
        cache[1] = 1;
        return cache[1];
    }
    cache[n] = _climbStairs_v2(n - 1, cache) + _climbStairs_v2(n - 2, cache);
    return cache[n];
}

int climbStairs_v2(int n)
{
    vector<int> cache(n + 1, -1);
    return _climbStairs_v2(n, cache);
}

/* Bottom-up */
int climbStairs(int n)
{
    vector<int> table(n + 1, 0);

    table[0] = 1;
    table[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        table[i] = table[i - 1] + table[i - 2];
    }

    return table[n];
}