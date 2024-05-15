#include <stdio.h>
#include <stdlib.h>
#include "../timeit.c"
#include "../../lib/mem_usage.c"

#define N 5000000
#define BITS_PER_WORD 32 // use int as word
#define MASK 0x1f        // BITS_PER_WORD - 1
#define SHIFT 5          // for bit operation

int a[1 + N / BITS_PER_WORD];

void set(int i)
{
    a[i >> SHIFT] |= 1 << (i & MASK);
}

int test(int i)
{
    return a[i >> SHIFT] & (1 << (i & MASK));
}

void clr(int i)
{
    a[i >> SHIFT] &= ~(1 << (i & MASK));
}

void sort(char *phone_numbers_filename, char *output_filename)
{
    FILE *input = fopen(phone_numbers_filename, "r");
    if (!input)
    {
        fprintf(stderr, "Could not open file '%s' for reading.\n", phone_numbers_filename);
    }

    // first time read and write phone numbers which less than N

    char line[256];
    while (fgets(line, sizeof(line), input) != NULL)
    {
        int phone_number = atoi(line);
        if (phone_number < N)
        {
            set(phone_number);
        }
    }

    FILE *output = fopen(output_filename, "w");

    for (int i = 0; i < N; i++)
    {
        if (test(i))
        {
            fprintf(output, "%d\n", i);
        }
    }

    // clear array

    for (int i = 0; i < N; i++)
    {
        clr(i);
    }

    // second time read and write phone numbers which more than N

    rewind(input);
    while (fgets(line, sizeof(line), input) != NULL)
    {
        int phone_number = atoi(line);
        if (phone_number > N)
        {
            set(phone_number - N);
        }
    }
    fclose(input);

    for (int i = 0; i < N; i++)
    {
        if (test(i))
        {
            fprintf(output, "%d\n", i + N);
        }
    }
    fclose(output);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <phone numbers filename> <output filename>\n", argv[0]);
        return 1;
    }

    timeit(sort, argv[1], argv[2]);
    show_mem_usage();
}