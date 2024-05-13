
#include <sys/resource.h>

void show_mem_usage()
{
    struct rusage r_usage;
    getrusage(RUSAGE_SELF, &r_usage);
    printf("Memory usage: %ld kilobytes\n", r_usage.ru_maxrss);
}