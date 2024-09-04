#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: July 5, 2024
 * Problem: Remove Element
 * Level: Easy
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Static Arrays
 */

int removeElement(vector<int> &nums, int val)
{
	int k = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[k] == val)
		{
			for (int j = k + 1; j < nums.size(); j++)
			{
				nums[j - 1] = nums[j];
			}
		}
		else
		{
			k++;
		}
	}

	return k;
}

int removeElement_v2(vector<int> &nums, int val)
{
	int k = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != val)
		{
			nums[k++] = nums[i];
		}
	}

	return k;
}
