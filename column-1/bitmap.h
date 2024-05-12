#define N 10000000
#define BITS_PER_WORD 32 // use int as word
#define MASK 0x1f        // BITS_PER_WORD - 1
#define SHIFT 5          // for bit operation

// phase 1: initialize set to empty
int a[1 + N / BITS_PER_WORD];

void set(int);
int test(int);