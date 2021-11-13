#ifndef _SCHEDULER_H
#define _SCHEDULER_H
#include "procqueue.h"

typedef struct
{
    queue* q;
    int quantum;
} start_sched_params;

void* start_sched(void* params);
#endif