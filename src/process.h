#ifndef _PCB_H
#define _PCB_H

typedef struct
{
    long pid;
    float lifetime;
} pcb;

#endif

#ifndef _QUEUE_H
#define _QUEUE_H
#include <stdlib.h>

typedef struct
{
    pcb *queue;
    int last;
    int size;
} queue;

void init_queue(queue *q, int size)
{
    q = (queue *)malloc(sizeof(queue) * size);
    q->last = 0;
    q->size = size;
}

pcb *item_at(int index, queue *q)
{
    return &(q->queue[index]);
}
#endif