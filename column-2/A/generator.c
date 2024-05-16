// generate a file that contains at most four billion 32-bit integers in random order.

#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

int main(int argc, char const *argv[])
{
    FILE *output = fopen(INTS_FILENAME, "w");

    // when N = 4,000,000,000 the file size is about 39 GB
    for (long i = 0; i < N; i++)
    {
        // TODO also generate negative numbers
        int n = rand();
        fprintf(output, "%d\n", n);
    }

    fclose(output);

    return 0;
}
