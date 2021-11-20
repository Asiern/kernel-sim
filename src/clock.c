#include "clock.h"
#include "globals.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

/* GLOBALS */
unsigned long tick;
unsigned long _time;
pthread_mutex_t clock_mtx;

/**
 * @brief Initialize clock
 * @param m machine pointer
 * @param t timer pointer
 * @param c clock pointer
 * @return (void)
 */
void init_clock(machine* m, timer* t, clock_k* c)
{
    c = (clock_k*)malloc(sizeof(clock_k));
    c->machine = m;
    c->timer = t;
}

/**
 * @brief Clock thread worker
 * @param params
 * @return (void)
 */
void* start_clock(void* params)
{
    int i;
    start_clock_params* param = (start_clock_params*)params;
    while (1)
    {
        if (tick < 180000000)
        {
            tick++;
            continue;
        }
        pthread_mutex_lock(&clock_mtx);
        tick = 0;
        /* Avanzar estructura CPUs */

        /* Señalar al timer */
        _time++;
        printf("%ld\n", _time);
        pthread_mutex_unlock(&clock_mtx);
    }
}
pthread_mutex_t clock_mutex;