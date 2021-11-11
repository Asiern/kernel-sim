#include "process.h"
#include "globals.h"
#include "semaphore.h"
unsigned long last_id;

pcb create_pcb(void)
{
    pcb p;
    p.pid = last_id + 1;
    p.lifetime = rand();
    return p;
}

void* start_pcb(void* params)
{
    start_pcb_params* param = (start_pcb_params*)param;
    while (1)
    {
        // pcb obj = create_pcb();
        // sem_wait(proc_queue_sem);
        // pthread_mutex_lock
    }
}