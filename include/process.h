#ifndef _PCB_H
#define _PCB_H

#include "globals.h"
#include <stdlib.h>
typedef struct
{
    long pid;
    float lifetime;
} pcb;

typedef struct
{
    pcb* queue;
    int first;
    int last;
} queue;

void init_queue(queue* q);
void addItem(queue* q, pcb* item);
pcb pop_queue(queue* q);
void move_queue(queue* q);

pcb create_pcb(void);
typedef struct
{
    queue* q;
} start_pcb_params;

void* start_pcb(queue* q);

#endif
