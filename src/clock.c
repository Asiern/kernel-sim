#include "clock.h"

/* GLOBALS */
unsigned int tick;
pthread_mutex_t clock_mtx;

/**
 * @brief Clock thread worker
 * @param params
 * @return (void)
 */
void* start_clock(void)
{
    while (1)
    {
        pthread_mutex_lock(&clock_mtx);
        tick++;
        pthread_mutex_unlock(&clock_mtx);
    }
}