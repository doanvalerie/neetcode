#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: July 5, 2024
 * Problem: Concatenation of Array
 * Level: Easy
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Dynamic Arrays
 */

vector<int> getConcatenation(vector<int> &nums)
{
	int n = nums.size();
	vector<int> ans;

	for (int i = 0; i < 2 * n; i++)
	{
		ans.push_back(nums[i % n]);
	}

	return ans;
}
