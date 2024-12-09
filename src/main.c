#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "util.h"
#include "matrix.h"
#include "p_queue.h"

#if defined(A_STAR)

typedef struct {
    int f;
    int g;
    int h;
} score_t;

int cmp(const void * a, const void * b)
{
    score_t val_a = *(score_t *)a;
    score_t val_b = *(score_t *)b;
    return val_a.f - val_b.f;
}

#elif defined(GBS)

typedef int score_t;

int cmp(const void * a, const void * b)
{
    int val_a = *(int *)a;
    int val_b = *(int *)b;
    return val_a - val_b;
}

#endif

typedef struct {
    int idx;
    score_t score;
} agent_t;

typedef p_queue_t(agent_t) p_queue_agent_t;

int main()
{
    struct timespec start, end;
    cell_t matrix[MAT_SIZE];

    p_queue_agent_t pq;

    agent_t current;

    // init structures
    matrix_init(matrix);
    p_queue_init(&pq, cmp);
    print_matrix();

    // mark starting time
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    // put starting cell into the priority queue
    current.idx = CHAR2INT(START_CELL);
#if defined(A_STAR)
    current.score.g = 0;
    current.score.h = manhattan_distance(current.idx, CHAR2INT(GOAL_CELL));
    current.score.f = current.score.g + current.score.h;
#elif defined(GBS)
    current.score = manhattan_distance(current.idx, CHAR2INT(GOAL_CELL));
#endif
    p_queue_set(&pq, current);

    while (!p_queue_empty(&pq)) {
        current = *p_queue_pop(&pq);

#if defined(A_STAR) && defined(DEBUG)
        printf("-> %c: %d = %d + %d\n", INT2CHAR(current.idx), current.score.f, current.score.g, current.score.h);
#elif defined(GBS) && defined(DEBUG)
        printf("-> %c: %d\n", INT2CHAR(current.idx), current.score);
#endif

        if (INT2CHAR(current.idx) == GOAL_CELL) break;

        for (int i = 0; i < MAT_SIZE; i++) {
            agent_t neighbor = { .idx = i };

            // check if it's adjacent and wasn't explored
            if (matrix[current.idx].adj_matrix[neighbor.idx]
            && !matrix[neighbor.idx].explored)
            {
#if defined(A_STAR)
                neighbor.score.g = current.score.g + 1;
                neighbor.score.h =
                    manhattan_distance(neighbor.idx, CHAR2INT(GOAL_CELL));
                neighbor.score.f = neighbor.score.g + neighbor.score.h;
#elif defined(GBS)
                neighbor.score =
                    manhattan_distance(neighbor.idx, CHAR2INT(GOAL_CELL));
#endif
                p_queue_set(&pq, neighbor);
                matrix[neighbor.idx].came_from = current.idx;
            }
        }

        matrix[current.idx].explored = true;
    }

    // mark finishing time
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    if (current.idx == CHAR2INT(GOAL_CELL)) {
        printf("Goal (%c cell) found\n", GOAL_CELL);
    } else {
        printf("Failed to find goal (%c cell)\n", GOAL_CELL);
    }
    printf("Time spent: %lld ns\n", delta_ns(start, end));
    size_t nodes_size = sizeof(p_queue_node_t) * pq.base.nodes_allocated;
    printf("Memory spend with nodes allocated: %ld bytes\n", nodes_size);

    matrix_print_path(matrix);

    p_queue_deinit(&pq);

    return 0;
}
