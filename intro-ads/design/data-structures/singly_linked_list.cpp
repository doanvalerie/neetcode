#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: July 6, 2024
 * Problem: Design Singly Linked List
 * Level: Easy
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Singly Linked Lists
 */

class Node
{
public:
	Node(int value) : value(value), next(nullptr) {}
	Node(int value, Node *next) : value(value), next(next) {}

	int value;
	Node *next;
};

class LinkedList
{
public:
	LinkedList()
	{
		/* Initialize dummy node. */
		dummy_head = new Node(-1);
		dummy_tail = dummy_head;
	}

	/* Return the value of the ith node (0-indexed). If the index is out of bounds, return -1. */
	int get(int index)
	{
		Node *curr = dummy_head->next;

		for (int i = 0; i < index; i++)
		{
			if (curr == nullptr)
			{
				return -1;
			}
			curr = curr->next;
		}

		if (curr == nullptr)
		{
			return -1;
		}
		return curr->value;
	}

	/* Insert a node with val at the head of the list. */
	void insertHead(int val)
	{
		Node *new_head = new Node(val, dummy_head->next);

		if (new_head->next == nullptr)
		{
			dummy_tail = new_head;
		}

		dummy_head->next = new_head;
	}

	/* Insert a node with val at the tail of the list. */
	void insertTail(int val)
	{
		dummy_tail->next = new Node(val);
		dummy_tail = dummy_tail->next;
	}

	/* Remove the ith node (0-indexed). If the index is out of bounds, return false, otherwise return true. */
	bool remove(int index)
	{
		Node *curr = dummy_head;

		for (int i = 0; i < index; i++)
		{
			curr = curr->next;
			if (curr == nullptr)
			{
				return false;
			}
		}

		if (curr->next == nullptr)
		{
			return false;
		}

		Node *removed_node = curr->next;
		curr->next = curr->next->next;
		delete removed_node;

		if (curr->next == nullptr)
		{
			dummy_tail = curr;
		}

		return true;
	}

	/* Return an array of all values in the linked list, ordered from head to tail. */
	vector<int> getValues()
	{
		vector<int> values;
		Node *curr = dummy_head->next;

		while (curr != nullptr)
		{
			values.push_back(curr->value);
			curr = curr->next;
		}

		return values;
	}

private:
	Node *dummy_head;
	Node *dummy_tail;
};
