#include "process.h"

/* GLOBALS */
unsigned long last_id;
sem_t proc_queue_sem;
pthread_mutex_t queue_mtx;
machine m;
queue q;

/**
 * @brief Initialize queue
 * @param q queue pointer
 * @param size queue size
 * @return (void)
 */
void init_queue(void)
{
    q = *(queue*)malloc(sizeof(queue));
    q.first = 0;
    q.last = -1;
    q.queue = (pcb*)malloc(sizeof(pcb) * queue_size);
}

/**
 * @brief Add pcb at queue end
 * @param q queue pointer
 * @param item pcb pointer
 * @return (void)
 */
void addItem(pcb* item)
{
    q.last = (q.last + 1) % queue_size;
    q.queue[q.last] = *item;
#ifdef DEBUG
    printf("PCB added to position %d\n", q.last);
#endif
}

/**
 * @brief Pop first queue item
 * @param q queue struct pointer
 * @return first pcb at queue
 */
pcb pop_queue(void)
{
    pcb item;
    item = q.queue[q.first];
    q.first = (q.first + 1) % queue_size;
    return item;
}

/**
 * @brief Move queue
 * @param (void)
 * @return (void)
 */
void move_queue(void)
{
    cprint("Moviendo elementos de la cola\n", YELLOW);
    if (q.first == q.last)
    {
        printf("First: %d; Last: %d\n", q.first, q.last);
        cprint("Queue empty => Waiting for new process\n", YELLOW);
        return; /* No hay elementos en la cola */
    }
    /* pcb item = pop_queue(); Sacar el primer elemento */
    /* TODO Cambiar contexto */
}

/**
 * @brief Generate pcb
 * @param (void)
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
void* start_pcb(void)
{
    sleep(1);
    while (1)
    {
        pcb obj = create_pcb();
        while (modulo(q.first - 1, queue_size) == q.last)
        {
            /* While queue is full wait */
            cprint("Queue is full\n", RED);
            sleep(4);
        }
        cprint("Created new pcb\n", BLUE);
        pthread_mutex_lock(&queue_mtx);
        addItem(&obj); /* Add item to queue end */
        pthread_mutex_unlock(&queue_mtx);
    }
}