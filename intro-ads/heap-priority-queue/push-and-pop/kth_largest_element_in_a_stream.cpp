#include <queue>
#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: October 28, 2024
 * Problem: Kth Largest Element in a Stream
 * Level: Easy
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Push and Pop
 */

class KthLargest
{
public:
    KthLargest(int k, vector<int> &nums) : k(k)
    {
        for (int n : nums)
        {
            min_heap.push(n);
        }

        while (min_heap.size() > k)
        {
            min_heap.pop();
        }
    }

    int add(int val)
    {
        if (min_heap.size() < k)
        {
            min_heap.push(val);
        }
        else if (val > min_heap.top())
        {
            min_heap.pop();
            min_heap.push(val);
        }

        return min_heap.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k;
};
