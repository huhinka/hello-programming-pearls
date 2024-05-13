#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "sort.h"

static int a[N];
static size_t n = 0;

int intcomp(const void *a, const void *b)
{
    int a_val = *((int *)a);
    int b_val = *((int *)b);

    if (a_val < b_val)
        return -1;
    if (a_val > b_val)
        return 1;
    return 0;
}

void on_phone_number(int num)
{
    a[n] = num;
    n++;
}

void on_read_complete()
{
    qsort(a, n, sizeof(int), intcomp);
}

void write_into_output(FILE *output)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(output, "%d\n", a[i]);
    }
}