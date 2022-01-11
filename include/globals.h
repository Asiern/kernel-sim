#ifndef _GLOBALS_H
#define _GLOBALS_H
#include "types.h"
#include <pthread.h>
#include <semaphore.h>

#define queue_size 20 /* Tamaño de la cola de procesos */
#define tickrate 18000000

extern pthread_mutex_t clock_mtx; /* Mutex del reloj */
extern pthread_mutex_t timer_mtx; /* Mutex del temporizador */
extern pthread_mutex_t queue_mtx; /* Mutex de la cola de procesos */
extern unsigned long last_id;     /* Id del último proceso generado */
extern unsigned int tick;         /* Último tick del reloj */
extern unsigned int _time;        /* Tiempo del temporizador */
extern unsigned int quantum;      /* Quantum del scheduler */
extern unsigned int cpus;         /* Número de cpus */
extern unsigned int cores;        /* Número de cores por cpu */
extern unsigned int threads;      /* Número de hilos de un core */
extern machine m;                 /* Máquina */
extern queue q;                   /* Cola de procesos */
extern unsigned char* Memory;     /* Physical memory */

#endif