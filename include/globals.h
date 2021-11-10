#ifndef _GLOBALS_H
#define _GLOBALS_H

#include <pthread.h>
#include <semaphore.h>

#define queue_size 20

extern pthread_mutex_t clock_mtx;
extern sem_t proc_queue_sem;
extern unsigned long last_id;

#endif