#include "clock.h"
#include <stdio.h>
#include <stdlib.h>

void init_clock(machine* m, timer* t, clock_k* c)
{
    c = (clock_k*)malloc(sizeof(clock_k));
    c->machine = m;
    c->timer = t;
}

void* start_clock(void* params)
{
    int i;
    start_clock_params* param = (start_clock_params*)params;
    while (1)
    {
        /* Avanzar estructura CPUs */

        /* Señalar al timer */
    }
}
pthread_mutex_t clock_mutex;