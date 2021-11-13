#include "process.h"
#include "globals.h"
#include "procqueue.h"
#include "utils.h"
#include <semaphore.h>
#include <unistd.h>

/* GLOBALS */
unsigned long last_id;
sem_t proc_queue_sem;
pthread_mutex_t queue_mtx;

void init_queue(queue* q, int size)
{
    q = (queue*)malloc(sizeof(queue));
    q->first = 0;
    q->last = 0;
    q->size = size;
    q->queue = (pcb*)malloc(sizeof(pcb) * size);
}

void free_queue(queue* q)
{
    free(q->queue);
}

void addItem(queue* q, pcb* item)
{
    q->queue[q->last] = *item;
    q->last = (q->last + 1) % q->size;
}

pcb create_pcb(void)
{
    pcb p;
    p.pid = last_id + 1;
    p.lifetime = rand();
    return p;
}

void* start_pcb(queue* q)
{
    while (1)
    {
        while ((q->first - 1) % queue_size == q->last)
        {
        }
        pcb obj = create_pcb();
        pthread_mutex_lock(&queue_mtx);
        addItem(q, &obj);
        pthread_mutex_unlock(&queue_mtx);
        sleep(1);
    }
}