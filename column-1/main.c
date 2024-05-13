#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "sort.h"
#include "timeit.c"
#include "../lib/mem_usage.c"

void sort(char *phone_numbers_filename, char *output_filename)
{
    // phase 2: insert present elements into the set
    FILE *input = fopen(phone_numbers_filename, "r");
    if (!input)
    {
        fprintf(stderr, "Could not open file '%s' for reading.\n", phone_numbers_filename);
    }
    char line[256];
    while (fgets(line, sizeof(line), input) != NULL)
    {
        on_phone_number(atoi(line));
    }
    fclose(input);

    on_read_complete();

    // phase 3: write sorted output
    FILE *output = fopen(output_filename, "w");
    write_into_output(output);
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