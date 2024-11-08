#include <iostream>
#include <vector>

using namespace std;

int maximumProfit(vector<int> &profit, vector<int> &weight, int capacity)
{
    int max_profit = 0;
    vector<vector<int>> tab(profit.size() + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i < profit.size() + 1; i++)
    {
        for (int j = 1; j < capacity + 1; j++)
        {
            if (j - weight[i - 1] >= 0)
            {
                tab[i][j] = max(tab[i - 1][j], profit[i - 1] + tab[i - 1][j - weight[i - 1]]);
            }
            else
            {
                tab[i][j] = tab[i - 1][j];
            }
        }
    }

    return tab[profit.size()][capacity];
}

int main()
{
    vector<int> profit = {4, 4, 7, 1};
    vector<int> weight = {5, 2, 3, 1};
    int capacity = 8;
    cout << maximumProfit(profit, weight, capacity) << endl;
}