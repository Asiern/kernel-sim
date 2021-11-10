#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "clock.h"
#include "globals.h"
#include "machine.h"
#include "process.h"
#include "procqueue.h"
#include "utils.h"

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
            exit(1);
        default:
            printf("%s\n", "Illegal command arguments");
            exit(-1);
        }
    }

    /* Inicializar las estructuras */
    cprint("Inicializando estructuras...", BLUE);
    pthread_mutex_t clock_mutex;
    if (pthread_mutex_init(&clock_mutex, NULL))
    {
        cprint("Error al iniciar mutex", RED);
        exit(-1);
    }

    sem_t proc_queue_sem;
    if (sem_init(&proc_queue_sem, 0, queue_size))
    {
        cprint("Error al iniciar semaforo", RED);
        exit(-1);
    }

    /*TODO Inicializar machine*/
    machine m;
    init_machine(&m, cpus, cores, threads);

    /*TODO Inicializar timer*/
    timer t;

    /*Inicializar clock*/
    clock_k c;
    init_clock(&m, &t, &c);

    /*TODO Inicializar queue*/
    queue q;

    /*TODO Lanzar los hilos */
    cprint("Lanzando hilos...", BLUE);
    pthread_t clock_thread, pgen_thread, sched_thread, timer_thread;

    cprint("Creando hilo del Clock", 0);
    pthread_create(&clock_thread, NULL, (void*)start_clock(&c), (void*)&c);

    cprint("Creando hilo del PG", 0);
    cprint("Creando hilo del Timer", 0);

    pthread_join(&clock_thread, NULL);
    return 0;
}
