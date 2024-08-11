#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: July 17, 2024
 * Problem: Insertion Sort
 * Level: Easy
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Insertion Sort
 */

/*
 * Definition for a Pair
 * class Pair {
 * public:
 *     int key;
 *     string value;
 *
 *     Pair(int key, string value) : key(key), value(value) {}
 * }
 */

vector<vector<Pair>> insertionSort(vector<Pair> &pairs)
{
    vector<vector<Pair>> states;

    for (int i = 1; i < pairs.size(); i++)
    {
        int j = i;
        states.push_back(pairs);

        while (j - 1 >= 0 && pairs[j].key < pairs[j - 1].key)
        {
            Pair temp = pairs[j];
            pairs[j] = pairs[j - 1];
            pairs[j - 1] = temp;
            j--;
        }
    }

    if (pairs.size() > 0)
    {
        states.push_back(pairs);
    }

    return states;
}