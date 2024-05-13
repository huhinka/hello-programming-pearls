#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bitmap.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <phone numbers filename> <output filename>\n", argv[0]);
        return 1;
    }

    char *phone_numbers_filename = argv[1];
    char *output_filename = argv[2];

    // phase 2: insert present elements into the set
    FILE *input = fopen(phone_numbers_filename, "r");
    if (!input)
    {
        fprintf(stderr, "Could not open file '%s' for reading.\n", phone_numbers_filename);
        return 1;
    }
    char line[256];
    while (fgets(line, sizeof(line), input) != NULL)
    {
        set(atoi(line));
    }
    fclose(input);

    // phase 3: write sorted output
    FILE *output = fopen(output_filename, "w");
    for (int i = 0; i < N; i++)
    {
        if (test(i))
        {
            fprintf(output, "%d\n", i);
        }
    }
    fclose(output);
}