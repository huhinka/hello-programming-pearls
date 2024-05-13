#include <stdio.h>
#include "sort.h"
#include "bitmap.h"

void on_phone_number(int num)
{
    set(num);
}

void on_read_complete()
{
}

void write_into_output(FILE *output)
{
    for (int i = 0; i < N; i++)
    {
        if (test(i))
        {
            fprintf(output, "%d\n", i);
        }
    }
}