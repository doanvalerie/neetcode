#include <string>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: July 7, 2024
 * Problem: Design Browser History
 * Level: Medium
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Doubly Linked Lists
 */

/*
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

class PageNode
{
public:
	PageNode(string name) : name(name), prev(nullptr), next(nullptr) {}

	string name;
	PageNode *prev;
	PageNode *next;
};

class BrowserHistory
{
public:
	BrowserHistory(string homepage)
	{
		curr_page = new PageNode(homepage);
		head = curr_page;
		tail = curr_page;
	}

	void visit(string url)
	{
		PageNode *prev_page = curr_page;
		PageNode *next_page = prev_page->next;

		while (next_page != nullptr)
		{
			PageNode *temp = next_page->next;
			delete next_page;
			next_page = temp;
		}

		PageNode *new_page = new PageNode(url);
		tail = new_page;
		curr_page = new_page;

		prev_page->next = curr_page;
		curr_page->prev = prev_page;
	}

	string back(int steps)
	{
		int i = 0;

		while (curr_page != head)
		{
			i++;
			curr_page = curr_page->prev;

			if (i == steps)
			{
				break;
			}
		}

		return curr_page->name;
	}

	string forward(int steps)
	{
		int i = 0;

		while (curr_page != tail)
		{
			i++;
			curr_page = curr_page->next;

			if (i == steps)
			{
				break;
			}
		}

		return curr_page->name;
	}

private:
	PageNode *head;
	PageNode *tail;
	PageNode *curr_page;
};
