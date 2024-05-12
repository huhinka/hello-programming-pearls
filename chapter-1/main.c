#include <stdio.h>
#include "../lib/show_bytes.c"

#define N 10000000
#define BITS_PER_WORD 32 // use int as word
#define MASK 0x1f        // BITS_PER_WORD - 1
#define SHIFT 5          // for bit operation

// phase 1: initialize set to empty
int a[1 + N / BITS_PER_WORD];

void set(int i)
{
    a[i >> SHIFT] |= 1 << (i & MASK);
}

int test(int i)
{
    return a[i >> SHIFT] & (1 << (i & MASK));
}

int main()
{
    // phase 2: insert present elements into the set
    // use stdin as input
    int n;
    while (scanf("%d", &n) != EOF)
    {
        set(n);
    }

    // only show the first 3 elements for testing
    // the range of i is [0, 95]
    for (int j = 0; j < 3; j++)
    {
        show_int(a[j]);
    }

    // phase 3: write sorted output
    // sue stdout as output
    for (int i = 0; i < N; i++)
    {
        if (test(i))
        {
            printf("%d\n", i);
        }
    }
}