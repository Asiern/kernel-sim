#ifndef _CLOCK_H
#define _CLOCK_H

#include <pthread.h>

#include "globals.h"
#include "machine.h"
#include "timer.h"
#include "utils.h"

typedef struct
{
    timer* timer;
    machine* machine;
} clock_k;

void init_clock(machine* m, timer* t, clock_k* c);

void* start_clock(void* params);

typedef struct
{
    clock_k* c;
} start_clock_params;

#endif