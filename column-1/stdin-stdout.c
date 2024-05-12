#include <stdio.h>
#include "bitmap.h"
#include "../lib/show_bytes.c"

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