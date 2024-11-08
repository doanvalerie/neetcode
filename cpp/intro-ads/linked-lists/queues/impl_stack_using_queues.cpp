#include <queue>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: July 7, 2024
 * Problem: Implement Stack using Queues
 * Level: Easy
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Queues
 */

class MyStack
{
public:
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
        for (int i = 0; i < q1.size() - 1; i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop()
    {
        int front = q1.front();
        q1.pop();
        return front;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }

private:
    queue<int> q1;
};
