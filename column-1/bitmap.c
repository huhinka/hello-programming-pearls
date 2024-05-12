#include "bitmap.h"

void set(int i)
{
    a[i >> SHIFT] |= 1 << (i & MASK);
}

int test(int i)
{
    return a[i >> SHIFT] & (1 << (i & MASK));
}