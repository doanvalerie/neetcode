/*
 * Author: Valerie Doan
 * Date: July 5, 2024
 * Problem: Design Dynamic Array (Resizable Array)
 * Level: Easy
 * Neetcode Course: Algorithms and Data Structures for Beginners
 * Neetcode Topic: Dynamic Arrays
 */

class DynamicArray
{
public:
    DynamicArray(int capacity) : capacity(capacity), length(0)
    {
        arr = new int[capacity];
    }

    int get(int i)
    {
        return arr[i];
    }

    void set(int i, int n)
    {
        arr[i] = n;
    }

    void pushback(int n)
    {
        if (length == capacity)
        {
            resize();
        }
        arr[length++] = n;
    }

    int popback()
    {
        return arr[--length];
    }

    void resize()
    {
        capacity *= 2;
        int *new_arr = new int[capacity];
        for (int i = 0; i < length; i++)
        {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
    }

    int getSize()
    {
        return length;
    }

    int getCapacity()
    {
        return capacity;
    }

private:
    int *arr;
    int length;
    int capacity;
};
