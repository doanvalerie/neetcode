#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 11, 2024
 * Problem: Min Cost Climbing Stairs
 * Level: Easy
 * Neetcode Course: Neetcode 150
 * Neetcode Topic: 1-D DP
 */

int minCostClimbingStairs(vector<int> &cost)
{
    vector<int> mem(cost.size(), 0);

    mem[0] = cost[0];
    mem[1] = cost[1];

    for (int i = 2; i < cost.size(); i++)
    {
        mem[i] = cost[i] + min(mem[i - 1], mem[i - 2]);
    }

    return min(mem[cost.size() - 1], mem[cost.size() - 2]);
}