/*
 * Author: Valerie Doan
 * Date: July 7, 2024
 * Problem: Design Linked List
 * Level: Medium
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Doubly Linked Lists
 */

/*
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

class Node
{
public:
    Node(int value) : value(value), prev(nullptr), next(nullptr) {}
    Node(int value, Node *prev, Node *next) : value(value), prev(prev), next(next) {}

    int value;
    Node *prev;
    Node *next;
};

class MyLinkedList
{
public:
    MyLinkedList()
    {
        /* Initialize dummy nodes. */
        dummy_head = new Node(-1);
        dummy_tail = new Node(-1);

        dummy_head->next = dummy_tail;
        dummy_tail->prev = dummy_head;
    }

    int get(int index)
    {
        Node *curr = dummy_head->next;
        int i = 0;

        while (curr != dummy_tail)
        {
            if (i == index)
            {
                return curr->value;
            }

            curr = curr->next;
            i++;
        }

        return -1;
    }

    void addAtHead(int val)
    {
        Node *new_head = new Node(val);
        Node *old_head = dummy_head->next;

        old_head->prev = new_head;
        new_head->prev = dummy_head;
        new_head->next = old_head;
        dummy_head->next = new_head;
    }

    void addAtTail(int val)
    {
        Node *new_tail = new Node(val);
        Node *old_tail = dummy_tail->prev;

        old_tail->next = new_tail;
        new_tail->prev = old_tail;
        new_tail->next = dummy_tail;
        dummy_tail->prev = new_tail;
    }

    void addAtIndex(int index, int val)
    {
        Node *curr = dummy_head;
        int i = 0;

        while (curr != dummy_tail)
        {
            if (i == index)
            {
                Node *new_node = new Node(val);
                Node *next = curr->next;

                new_node->prev = curr;
                new_node->next = next;
                next->prev = new_node;
                curr->next = new_node;

                return;
            }

            curr = curr->next;
            i++;
        }
    }

    void deleteAtIndex(int index)
    {
        Node *curr = dummy_head;
        int i = 0;

        while (curr->next != dummy_tail)
        {
            if (i == index)
            {
                Node *removed_node = curr->next;
                removed_node->next->prev = curr;
                curr->next = removed_node->next;

                delete removed_node;
                return;
            }

            curr = curr->next;
            i++;
        }
    }

private:
    Node *dummy_head;
    Node *dummy_tail;
};
