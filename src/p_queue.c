#include "p_queue.h"

#include <stdio.h>
#include <string.h>

bool p_queue_empty_(p_queue_base_t *pq)
{
    return pq->first == NULL;
}

void p_queue_init_(p_queue_base_t *pq, int (*cmp)(const void *, const void*))
{
    *pq = (p_queue_base_t) {
        .first = NULL,
        .nodes_allocated = 0,
        .cmp = cmp
    };
}

void p_queue_deinit_(p_queue_base_t *pq)
{
    p_queue_node_t *rm;

    while (!p_queue_empty_(pq)) {
        rm = pq->first;
        pq->first = rm->next;
        free(rm->data);
        free(rm);
    }
}

void p_queue_set_(p_queue_base_t *pq, void *data, size_t data_size)
{
    p_queue_node_t *new_node = (p_queue_node_t *)malloc(sizeof(p_queue_node_t));
    if (new_node == NULL) {
        perror("Memory allocation failure for new node\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = malloc(data_size);
    if (new_node->data == NULL) {
        perror("Memory allocation failure for new node data\n");
        exit(EXIT_FAILURE);
    }

    memcpy(new_node->data, data, data_size);

    if (p_queue_empty_(pq) || pq->cmp(new_node->data, pq->first->data) < 0) {
        new_node->next = pq->first;
        pq->first = new_node;
    } else {
        p_queue_node_t *iter = pq->first;

        // Inserção após nós com o mesmo valor
        while (iter->next != NULL &&
               pq->cmp(iter->next->data, new_node->data) <= 0)
        {
            iter = iter->next;
        }

        new_node->next = iter->next;
        iter->next = new_node;
    }

    pq->nodes_allocated++;
}

void *p_queue_pop_(p_queue_base_t *pq, void *ref, size_t data_size)
{
    if (p_queue_empty_(pq)) {
        perror("Error: attempting to pop from an empty priority queue\n");
        exit(EXIT_FAILURE);
    }

    p_queue_node_t *rm;

    rm = pq->first;
    memcpy(ref, rm->data, data_size);
    pq->first = rm->next;

    free(rm->data);
    free(rm);

    return ref;
}
