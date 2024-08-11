/*
 * Author: Valerie Doan
 * Date: July 7, 2024
 * Problem: Design Double-ended Queue
 * Level: Easy
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Queues
 */

class Node
{
public:
	Node(int value) : value(value), prev(nullptr), next(nullptr) {}

	int value;
	Node *prev;
	Node *next;
};

class Deque
{
public:
	Deque()
	{
		dummy_head = new Node(-1);
		dummy_tail = new Node(-1);

		dummy_head->next = dummy_tail;
		dummy_tail->prev = dummy_head;
	}

	bool isEmpty()
	{
		return dummy_head->next == dummy_tail;
	}

	void append(int value)
	{
		Node *old_tail = dummy_tail->prev;
		Node *new_tail = new Node(value);

		old_tail->next = new_tail;
		new_tail->prev = old_tail;
		new_tail->next = dummy_tail;
		dummy_tail->prev = new_tail;
	}

	void appendleft(int value)
	{
		Node *old_head = dummy_head->next;
		Node *new_head = new Node(value);

		old_head->prev = new_head;
		new_head->prev = dummy_head;
		new_head->next = old_head;
		dummy_head->next = new_head;
	}

	int pop()
	{
		Node *removed_tail = dummy_tail->prev;
		int removed_val = removed_tail->value;

		if (removed_tail == dummy_head)
		{
			return -1;
		}

		removed_tail->prev->next = dummy_tail;
		dummy_tail->prev = removed_tail->prev;

		delete removed_tail;
		return removed_val;
	}

	int popleft()
	{
		Node *removed_head = dummy_head->next;
		int removed_val = removed_head->value;

		if (removed_head == dummy_tail)
		{
			return -1;
		}

		removed_head->next->prev = dummy_head;
		dummy_head->next = removed_head->next;

		delete removed_head;
		return removed_val;
	}

private:
	Node *dummy_head;
	Node *dummy_tail;
};
