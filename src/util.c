#include "util.h"

#include <stdio.h>

long long delta_ns(const struct timespec start, const struct timespec end)
{
    return (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
}

void print_matrix()
{
    printf("Input matrix:\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c ", ((5 * i + j) % 26) + 'A');
        }
        printf("\n");
    }
}

