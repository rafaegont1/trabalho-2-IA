#ifndef CELL_H
#define CELL_H

#include <stdio.h>
#include <stdbool.h>
#include "util.h"

#define ROWS 5
#define COLS 5
#define MAT_SIZE ROWS * COLS
#define START_CELL 'U'
#define GOAL_CELL 'E'

#define ROW(idx) ((idx) / COLS)
#define COL(idx) ((idx) % COLS)

typedef struct {
    int came_from;
    bool explored;
    bool adj_matrix[MAT_SIZE];
} cell_t;

void matrix_init(cell_t *matrix);
// void matrix_print_path(const cell_t *matrix);
int manhattan_distance(int from, int to);

#endif // CELL_H
