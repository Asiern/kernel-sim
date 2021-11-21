#include "scheduler.h"

/* GLOBALS */
unsigned int quantum;
unsigned int _time;
pthread_mutex_t timer_mtx;
queue q;

void* start_sched(void)
{
    while (1)
    {
        if (_time < quantum)
            continue;
        pthread_mutex_lock(&timer_mtx);
        _time = 0; /* Reiniciar el temporizador */
        pthread_mutex_unlock(&timer_mtx);

        /* Expulsion por tiempo */
        cprint("Quantum alcanzado => Expulsión por tiempo\n", CYAN);
        pthread_mutex_lock(&queue_mtx);
        move_queue();
        pthread_mutex_unlock(&queue_mtx);
    }
}
