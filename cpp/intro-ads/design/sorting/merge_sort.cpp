#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: August 7, 2024
 * Problem: Merge Sort
 * Level: Medium
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Merge Sort
 */

/*
 * Definition for a Pair
 * class Pair {
 * public:
 *     int key;
 *     string value;
 *
 *     Pair(int key, string value) : key(key), value(value) {}
 * };
 */

void merge(vector<Pair> &pairs, int start, int mid, int end)
{
    vector<Pair> left;
    vector<Pair> right;

    for (int i = start; i <= mid; i++)
    {
        left.push_back(pairs[i]);
    }

    for (int i = mid + 1; i <= end; i++)
    {
        right.push_back(pairs[i]);
    }

    int i = 0;
    int j = 0;
    int k = start;

    while (i < left.size() && j < right.size())
    {
        if (left[i].key <= right[j].key)
        {
            pairs[k++] = left[i++];
        }
        else
        {
            pairs[k++] = right[j++];
        }
    }

    while (i < left.size())
    {
        pairs[k++] = left[i++];
    }

    while (j < right.size())
    {
        pairs[k++] = right[j++];
    }
}

void _mergeSort(vector<Pair> &pairs, int start, int end)
{
    if (end - start <= 0)
    {
        return;
    }

    int mid = (start + end) / 2;

    _mergeSort(pairs, start, mid);
    _mergeSort(pairs, mid + 1, end);
    merge(pairs, start, mid, end);
}

vector<Pair> mergeSort(vector<Pair> &pairs)
{
    _mergeSort(pairs, 0, pairs.size() - 1);
    return pairs;
}