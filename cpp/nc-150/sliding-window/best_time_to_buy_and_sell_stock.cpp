#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 11, 2024
 * Problem: Best Time to Buy and Sell Stock
 * Level: Easy
 * Neetcode Course: Neetcode 150
 * Neetcode Topic: Sliding Window
 */

int maxProfit(vector<int> &prices)
{
    int profit = 0;
    int L = 0;

    for (int R = 0; R < prices.size(); R++)
    {
        while (prices[R] - prices[L] < 0)
        {
            L++;
        }

        profit = max(prices[R] - prices[L], profit);
    }

    return profit;
}