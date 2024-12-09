#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <time.h>

#define CHAR2INT(x) ((x) - 'A')
#define INT2CHAR(x) ((x) + 'A')

typedef struct position_s position_t;

struct position_s
{
    char letter;
    int idx;
};

long long delta_ns(const struct timespec start, const struct timespec end);
void print_matrix();
// void print_path(const char *predecessor);

#endif // UTIL_H
