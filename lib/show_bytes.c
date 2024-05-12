#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = len - 1; i < len; i--)
    {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_char(char x)
{
    printf("char %d:", x);
    show_bytes((byte_pointer)&x, sizeof(char));
}

void show_short(short x)
{
    printf("short %d:", x);
    show_bytes((byte_pointer)&x, sizeof(short));
}

void show_int(int x)
{
    printf("int %d:", x);
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_unsigned(unsigned x)
{
    printf("unsigned %u:", x);
    show_bytes((byte_pointer)&x, sizeof(unsigned));
}

void show_long(long x)
{
    printf("long %ld:", x);
    show_bytes((byte_pointer)&x, sizeof(long));
}

void show_float(float x)
{
    printf("float %f:", x);
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
    printf("pointer %p:", x);
    show_bytes((byte_pointer)&x, sizeof(void *));
}

void show_string(char *s)
{
    printf("string '%s':", s);
    show_bytes((byte_pointer)s, strlen(s));
}