#include "process.h"
#include "globals.h"
#include "utils.h"
#include <semaphore.h>
#include <unistd.h>

/* GLOBALS */
unsigned long last_id;
sem_t proc_queue_sem;
pthread_mutex_t queue_mtx;

/**
 * @brief Initialize queue
 * @param q queue pointer
 * @param size queue size
 * @return (void)
 */
void init_queue(queue* q)
{
    q = (queue*)malloc(sizeof(queue));
    q->first = 0;
    q->last = -1;
    q->queue = (pcb*)malloc(sizeof(pcb) * queue_size);
}

/**
 * @brief Add pcb at queue end
 * @param q queue pointer
 * @param item pcb pointer
 * @return (void)
 */
void addItem(queue* q, pcb* item)
{
    q->queue[q->last] = *item;
    q->last = (q->last + 1) % queue_size;
}

/**
 * @brief Pop first queue item
 * @param q queue struct pointer
 * @return first pcb at queue
 */
pcb pop_queue(queue* q)
{
    pcb item;
    pthread_mutex_lock(&queue_mtx);
    item = q->queue[q->first];
    q->first = (q->first + 1) % queue_size;
    pthread_mutex_unlock(&queue_mtx);
    return item;
}

void move_queue(queue* q)
{
    pcb item = pop_queue(q);
}

/**
 * @brief Generate pcb
 * @param void
 * @return Generated pcb
 */
pcb create_pcb(void)
{
    pcb p;
    p.pid = last_id + 1;
    p.lifetime = rand();
    return p;
}

/**
 * @brief PCB Generator thread worker
 * @param q queue pointer
 * @return (void)
 */
void* start_pcb(queue* q)
{
    while (1)
    {
        pcb obj = create_pcb();
        while (modulo(q->first - 1, queue_size) == q->last)
        {
            /* While queue is full wait */
            cprint("Queue is full", RED);
            sleep(2);
        }
        cprint("Created new pcb", BLUE);
        pthread_mutex_lock(&queue_mtx);
        addItem(q, &obj); /* Add item to queue end */
        pthread_mutex_unlock(&queue_mtx);
    }
}