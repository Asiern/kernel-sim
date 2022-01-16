#include "scheduler.h"

/* GLOBALS */
unsigned int quantum;
unsigned int _time;
pthread_mutex_t timer_mtx;
pthread_mutex_t machine_mtx;
queue q;
machine m;
unsigned int nextThreadId;

/**
 * @brief Scheduler thread worker
 * @param (void)
 * @return (void)
 */
void* start_sched(void)
{
    nextThreadId = 0;
    while (1)
    {
        if (_time < quantum)
            continue;
        pthread_mutex_lock(&timer_mtx);
        _time = 0; /* Reiniciar el temporizador */
        pthread_mutex_unlock(&timer_mtx);

        /* Expulsion por tiempo */
        cprint("[SCHED] Quantum alcanzado => Expulsión por tiempo\n", CYAN);
        pthread_mutex_lock(&queue_mtx);
        pthread_mutex_lock(&machine_mtx);
        for (unsigned int i = 0; i < cpus * cores * threads; i++)
        {
            if (isThreadBusy(i) == 1)
            {
                pcb* oldProcess = getPCB(i);
                pcb* newProcess = pop_queue();
                addItem(oldProcess);
                printf("[SCHED] Loading process pid: %ld to thread tid: %d\n", newProcess->pid, i);
                loadPCB(i, newProcess);
            }
            else
            {
                pcb* p = pop_queue();
                printf("[SCHED] Loading process pid: %ld to free thread tid: %d\n", p->pid, i);
                loadPCB(i, p);
            }
        }
        pthread_mutex_unlock(&machine_mtx);
        pthread_mutex_unlock(&queue_mtx);
    }
}
