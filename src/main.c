#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "clock.h"
#include "globals.h"
#include "machine.h"
#include "process.h"
#include "scheduler.h"
#include "timer.h"
#include "utils.h"

/* GLOBALS */
pthread_mutex_t clock_mutex;
sem_t proc_queue_sem;

int main(int argc, char* const argv[])
{
    /* Get params */
    int opt, quantum = 0, cpus = 0, cores = 0, threads = 0;

    while ((opt = getopt(argc, argv, "h,q:c:r:t:")) != -1)
    {
        switch (opt)
        {
        case 'q':
            quantum = atoi(optarg);
            break;
        case 'c':
            cpus = atoi(optarg);
            break;
        case 'r':
            cores = atoi(optarg);
            break;
        case 't':
            threads = atoi(optarg);
            break;
        case 'h':
            cprint("Kernel Sim", MAGENTA);
            cprint("Uso:", MAGENTA);
            return 0;
        default:
            printf("%s\n", "Illegal command arguments");
            return 1;
        }
    }

    /* Inicializar las estructuras */
    cprint("Inicializando estructuras...", GREEN);
    if (pthread_mutex_init(&clock_mutex, NULL) != 0)
    {
        cprint("Error al iniciar mutex", RED);
        return 1;
    }

    if (sem_init(&proc_queue_sem, 0, queue_size) != 0)
    {
        cprint("Error al iniciar semaforo", RED);
        return 1;
    }

    /* Inicializar machine */
    machine m;
    init_machine(&m, cpus, cores, threads);

    /*TODO Inicializar timer*/
    timer t;

    /* Inicializar clock */
    clock_k c;
    init_clock(&m, &t, &c);

    /*TODO Inicializar queue */
    queue q;
    init_queue(&q, queue_size);

    /* Lanzar los hilos */
    cprint("Lanzando hilos...", GREEN);
    pthread_t clock_thread, pgen_thread, sched_thread, timer_thread;

    cprint("Creando hilo del Clock", 0);
    start_clock_params* clock_params = (start_clock_params*)malloc(sizeof(start_clock_params));
    clock_params->c = &c;
    pthread_create(&clock_thread, NULL, (void*)start_clock, (void*)clock_params);

    cprint("Creando hilo del PG", 0);
    start_pcb_params* pcb_params = (start_pcb_params*)malloc(sizeof(start_pcb_params));
    pcb_params->q = &q;
    pthread_create(&pgen_thread, NULL, (void*)start_pcb, (void*)pcb_params);

    cprint("Creando hilo del Timer", 0);
    start_timer_params* timer_params = (start_timer_params*)malloc(sizeof(start_timer_params));
    timer_params->t = &t;
    pthread_create(&timer_thread, NULL, (void*)start_timer, (void*)timer_params);

    cprint("Creando hilo del Sched", 0);
    start_sched_params* sched_params = (start_sched_params*)malloc(sizeof(start_sched_params));
    /*TODO Define start_sched params */
    sched_params->quantum = quantum;
    sched_params->q = &q;
    pthread_create(&sched_thread, NULL, (void*)start_sched, (void*)sched_params);

    /* EL PROGRAMA NO DEBERIA DE PASAR DE AQUI */

    /* Join */
    pthread_join(clock_thread, NULL);
    pthread_join(pgen_thread, NULL);
    pthread_join(timer_thread, NULL);
    pthread_join(sched_thread, NULL);

    return 0;
}
