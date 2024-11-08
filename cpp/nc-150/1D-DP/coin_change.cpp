#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 16, 2024
 * Problem: Coin Change
 * Level: Medium
 * Neetcode Course: Neetcode 150
 * Neetcode Topic: 1-D DP
 */

int coinChange(vector<int> &coins, int amount)
{
    int table[amount + 1];
    fill_n(table, amount + 1, -1);
    table[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (i - coin >= 0 && table[i - coin] != -1)
            {
                if (table[i] == -1)
                {
                    table[i] = 1 + table[i - coin];
                }
                else
                {
                    table[i] = min(table[i], 1 + table[i - coin]);
                }
            }
        }
    }

    return table[amount];
}