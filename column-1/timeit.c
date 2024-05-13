#include <stdio.h>
#include <time.h>

void timeit(void (*sortFuncPtr)(char *, char *), char *input_filename, char *output_filename)
{
    clock_t start = clock();

    sortFuncPtr(input_filename, output_filename);

    clock_t end = clock();
    double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time);
}