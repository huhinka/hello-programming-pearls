#include <stdio.h>

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000

int a[1 + N / BITSPERWORD];

void set(int i)
{
    printf("i: %d\nindex: %d\nright value: %d\n", i, i >> SHIFT, 1 << (i & MASK));
    a[i >> SHIFT] |= (1 << (i & MASK));
}

void clr(int i)
{
    a[i >> SHIFT] &= ~(1 << (i & MASK));
}

int test(int i)
{
    return a[i >> SHIFT] & (1 << (i & MASK));
}

int main()
{
    printf("length of array a is %lu\n", sizeof(a));

    int i = 3;
    int index = i >> SHIFT;
    set(3);
    printf("value of index %d is %d\n", index, a[0]);
}