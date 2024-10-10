#include <cstdint>
#include <limits.h>

/*
 * Author: Valerie Doan
 * Date: October 10, 2024
 * Problem: Number of One Bits
 * Level: Easy
 * Neetcode Course: Neetcode 150
 * Neetcode Topic: Bit Manipulation
 */

int hammingWeight(uint32_t n)
{
    int total = 0;

    for (int i = 0; i < sizeof(uint32_t) * CHAR_BIT; i++)
    {
        total += (n & 1);
        n >>= 1;
    }

    return total;
}