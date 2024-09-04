#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: July 7, 2024
 * Problem: Climbing Stairs
 * Level: Easy
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Fibonacci Sequence
 */

int climbStairs(int n)
{
	vector<int> v;

	v.push_back(0);
	v.push_back(1);
	v.push_back(2);

	for (int i = 3; i <= n; i++)
	{
		v.push_back(v[i - 1] + v[i - 2]);
	}

	return v[n];
}

int climbStairs_v2(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}
	return climbStairs_v2(n - 1) + climbStairs_v2(n - 2);
}
