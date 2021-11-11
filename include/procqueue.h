#ifndef _QUEUE_H
#define _QUEUE_H
#include "process.h"
#include <stdlib.h>

typedef struct
{
    pcb* queue;
    int last;
    int size;
} queue;

void init_queue(queue* q, int size);
void free_queue(queue* q);
void addItem(queue* q, pcb* item);

#endif