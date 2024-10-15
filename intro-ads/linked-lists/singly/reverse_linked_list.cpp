/*
 * Author: Valerie Doan
 * Date: July 6, 2024
 * Problem: Reverse Linked List
 * Level: Easy
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Singly Linked Lists
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

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = head;
    ListNode *curr = nullptr;

    if (prev != nullptr)
    {
        curr = prev->next;
        prev->next = nullptr;
    }

    while (curr != nullptr)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}