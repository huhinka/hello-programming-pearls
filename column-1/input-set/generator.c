#include <stdio.h>
#include <stdlib.h>

#define N 10000000

const int MAX_SIZE = 3 * N / 4; // the size of the input set.
int set[N];

/**
 * Generate a random & unique phone number.
 */
int rand_phone_number()
{
    // Not effective, but simple.
    // NOTE: This is not a good way to generate a unique phone number.
    int phone_number = rand() % N;
    while (set[phone_number] != 0)
    {
        phone_number = rand() % N;
    }
    set[phone_number] = 1;

    return phone_number;
}

/**
 * Pads a phone number to be 7 digits.
 */
int pad(int phone_number)
{
    int padded = phone_number;
    const int edge = N / 10;
    while (padded < edge)
    {
        padded *= 10;
    }
    return padded;
}

/**
 * Generate a file with 5,000,000 unique phone numbers.
 */
int main()
{
    FILE *fptr = fopen("phone-numbers.txt", "w");

    for (int i = 0; i < MAX_SIZE; i++)
    {
        fprintf(fptr, "%d\n", pad(rand_phone_number()));
    }

    fclose(fptr);

    return 0;
}