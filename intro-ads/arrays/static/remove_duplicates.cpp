#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: July 5, 2024
 * Problem: Remove Duplicates from Sorted Array
 * Level: Easy
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Static Arrays
 */

int removeDuplicates(vector<int> &nums)
{
	int k = 0;
	int j = 1;

	while (j < nums.size())
	{
		if (nums[k] == nums[j])
		{
			j++;
		}
		else
		{
			nums[k + 1] = nums[j];
			k++;
		}
	}

	return k + 1;
}
