#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

#define SPLIT_FILE_ZERO "fzero"
#define SPLIT_FILE_ONE "fone"

typedef struct Result
{
    char *filename;
    int bit;
} result;

int check_bit(int n, int bit)
{
    return n & 1 << bit;
}

char *filename(char *zero_or_one, int bit)
{
    char *buf;

    int max_len = strlen(zero_or_one) + 10 + 4;
    buf = (char *)calloc(max_len, sizeof(char));

    snprintf(buf, max_len, "%s_%d.txt", zero_or_one, bit);

    return buf;
}

void split(struct Result *result_ptr, char *input_filename, int bit)
{
    if (bit >= 32)
    {
        fprintf(stderr, "Bit number too large\n");
        exit(1);
    }

    FILE *fcur = fopen(input_filename, "r");

    char *split_filename_one = filename(SPLIT_FILE_ONE, bit);
    char *split_filename_zero = filename(SPLIT_FILE_ZERO, bit);
    FILE *fzero = fopen(split_filename_zero, "w");
    FILE *fone = fopen(split_filename_one, "w");

    int num_zeros = 0;
    int num_ones = 0;

    char line[256];
    while (fgets(line, sizeof(line), fcur) != NULL)
    {
        int n = atoi(line);
        if (check_bit(n, bit))
        {
            num_ones++;
            fprintf(fone, "%d\n", n);
        }
        else
        {
            num_zeros++;
            fprintf(fzero, "%d\n", n);
        }
    }

    fclose(fcur);
    fclose(fzero);
    fclose(fone);

    if (num_zeros == 0 && num_ones == 0)
    {
        fprintf(stderr, "No data in file\n");
        exit(1);
    }

    if (num_zeros == 0 && num_ones != 0)
    {
        result_ptr->filename = split_filename_one;
        result_ptr->bit = bit;

        return;
    }
    else if (num_zeros != 0 && num_ones == 0)
    {
        result_ptr->filename = split_filename_zero;
        result_ptr->bit = bit;

        return;
    }

    int diff = num_zeros - num_ones;
    if (diff >= 0)
    {
        split(result_ptr, split_filename_one, bit + 1);
    }
    else
    {
        split(result_ptr, split_filename_zero, bit + 1);
    }
}

int reverse_bit(int n, int bit)
{
    // Reverse the bit at the given bit number
    n = n ^ (1 << bit);
    return n;
}

int main(int argc, char const *argv[])
{
    struct Result result;
    split(&result, INTS_FILENAME, 0);

    FILE *f = fopen(result.filename, "r");
    char line[256];
    // have one number at least
    if (fgets(line, sizeof(line), f) == NULL)
    {
        fprintf(stderr, "No data in file\n");
        return 1;
    }
    fclose(f);

    int n = atoi(line);
    int ret = reverse_bit(n, result.bit);
    printf("%d not in %s\n", ret, INTS_FILENAME);

    return 0;
}
