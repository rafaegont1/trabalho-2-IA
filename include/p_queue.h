#ifndef P_QUEUE_H
#define P_QUEUE_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct p_queue_node_s p_queue_node_t;
typedef struct p_queue_base_s p_queue_base_t;

struct p_queue_node_s {
    void *data;
    p_queue_node_t *next;
};

struct p_queue_base_s {
    p_queue_node_t *first;
    size_t nodes_allocated;
    int (*cmp)(const void *, const void *);
};

#define p_queue_t(T) \
    struct { p_queue_base_t base; T *ref; T tmp; }

#define p_queue_empty(pq) \
    p_queue_empty_(&(pq)->base)

#define p_queue_init(pq, cmp) \
    p_queue_init_(&(pq)->base, (cmp))

#define p_queue_deinit(pq) \
    p_queue_deinit_(&(pq)->base)

#define p_queue_set(pq, data) \
    ( (pq)->tmp = (data), \
    p_queue_set_(&(pq)->base, &(pq)->tmp, sizeof((pq)->tmp)) )

#define p_queue_pop(pq) \
    ( (pq)->ref = p_queue_pop_(&(pq)->base, &(pq)->tmp, sizeof((pq)->tmp)) )

bool p_queue_empty_(p_queue_base_t *pq);
void p_queue_init_(p_queue_base_t *pq, int (*cmp)(const void *, const void*));
void p_queue_deinit_(p_queue_base_t *pq);
void p_queue_set_(p_queue_base_t *pq, void *data, size_t data_size);
void *p_queue_pop_(p_queue_base_t *pq, void *ref, size_t data_size);
size_t p_queue_mem_used(p_queue_base_t *pq);

typedef p_queue_t(int) p_queue_int_t;

#endif // P_QUEUE_H
