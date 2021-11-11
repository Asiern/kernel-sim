#include "procqueue.h"

void init_queue(queue* q, int size)
{
    q = (queue*)malloc(sizeof(queue));
    q->last = 0;
    q->size = size;
    q->queue = (pcb*)malloc(sizeof(pcb) * size);
}

void free_queue(queue* q)
{
    free(q->queue);
}

void addItem(queue* q, pcb* item)
{
    q->queue[q->last] = *item;
    q->last = (q->last + 1) % q->size;
}
