#include <vector>

using namespace std;

/*
 * Author: Valerie Doan
 * Date: August 11, 2024
 * Problem: Merge K Sorted Lists
 * Level: Hard
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Merge Sort
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
 * O(n)
 */
ListNode *mergeTwoSortedLists(ListNode *list1, ListNode *list2)
{
    ListNode dummy;
    ListNode *curr = &dummy;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val <= list2->val)
        {
            curr->next = list1;
            list1 = list1->next;
        }
        else
        {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }

    if (list1 != nullptr)
    {
        curr->next = list1;
    }

    if (list2 != nullptr)
    {
        curr->next = list2;
    }

    return dummy.next;
}

/*
 * O(n * k)
 */
ListNode *mergeKLists_v2(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
    {
        return nullptr;
    }

    for (int i = 1; i < lists.size(); i++)
    {
        lists[0] = mergeTwoSortedLists(lists[0], lists[i]);
    }

    return lists[0];
}

/*
 * O(n * logk)
 */
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
    {
        return nullptr;
    }

    int k = lists.size();

    while (k > 1)
    {
        for (int i = 0; i < k / 2; i++)
        {
            lists[i] = mergeTwoSortedLists(lists[i], lists[k - 1 - i]);
        }

        k = (k + 1) / 2;
    }

    return lists[0];
}