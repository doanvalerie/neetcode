#include <queue>
#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: July 7, 2024
 * Problem: Number of Students Unable to Eat Lunch
 * Level: Easy
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Queues
 */

int countStudents(vector<int> &students, vector<int> &sandwiches)
{
	queue<int> q;

	for (int student : students)
	{
		q.push(student);
	}

	int i = 0;
	int rotations = 0;

	while (rotations != q.size())
	{
		if (q.front() == sandwiches[i])
		{
			i++;
			rotations = 0;
		}
		else
		{
			q.push(q.front());
			rotations++;
		}
		q.pop();
	}

	return q.size();
}
