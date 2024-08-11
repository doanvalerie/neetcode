#include <stack>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: July 5, 2024
 * Problem: Minimum Stack
 * Level: Medium
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Stacks
 */

class MinStack
{
public:
	MinStack() {}

	void push(int val)
	{
		int min = val;
		if (st.size() != 0 && st.top().second < min)
		{
			min = st.top().second;
		}
		st.push({val, min});
	}

	void pop()
	{
		st.pop();
	}

	int top()
	{
		return st.top().first;
	}

	int getMin()
	{
		return st.top().second;
	}

private:
	stack<pair<int, int>> st;
};
