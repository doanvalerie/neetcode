/*
 * Author: Valerie Doan
 * Date: July 6, 2024
 * Problem: Merge Two Sorted Linked Lists
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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode dummy;
    ListNode *curr = &dummy;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val > list2->val)
        {
            curr->next = list2;
            list2 = list2->next;
        }
        else
        {
            curr->next = list1;
            list1 = list1->next;
        }
        curr = curr->next;
    }

    if (list1)
    {
        curr->next = list1;
    }
    else if (list2)
    {
        curr->next = list2;
    }

    return dummy.next;
}
