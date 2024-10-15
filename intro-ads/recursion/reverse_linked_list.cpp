/*
 * Author: Valerie Doan
 * Date: July 7, 2024
 * Problem: Reverse Linked List
 * Level: Easy
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Factorial
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

ListNode *_reverseList(ListNode *head, ListNode *prev, ListNode *curr)
{
    if (head == prev)
    {
        head->next = nullptr;
    }

    if (curr == nullptr)
    {
        return prev;
    }

    ListNode *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;

    return _reverseList(head, prev, curr);
}

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    return _reverseList(head, head, head->next);
}
