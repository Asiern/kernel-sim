#include "timer.h"

/* GLOBALS */
unsigned int _time;
unsigned int tick;
pthread_mutex_t clock_mtx;
pthread_mutex_t timer_mtx;

/**
 * @brief Timer thread worker
 * @param (void)
 * @return (void)
 */
void* start_timer(void)
{
    while (1)
    {
        if (tick < tickrate)
            continue;
        pthread_mutex_lock(&clock_mtx);
        tick = 0;
        pthread_mutex_lock(&timer_mtx);
        _time++;
        printf("[TIMER] %d\n", _time);
        pthread_mutex_unlock(&timer_mtx);
        pthread_mutex_unlock(&clock_mtx);
    }
}
