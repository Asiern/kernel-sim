#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "clock.h"
#include "globals.h"
#include "loader.h"
#include "machine.h"
#include "physical.h"
#include "scheduler.h"
#include "timer.h"
#include "utils.h"

/* GLOBALS */
pthread_mutex_t clock_mutex;
sem_t proc_queue_sem;
unsigned int quantum = 4, cpus = 1, cores = 2, threads = 2;
machine m;

int main(int argc, char* const argv[])
{
    /* Get params */
    int opt;

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
            cprint("[ KERNEL SIM ]\n", CYAN);
            cprint("USAGE:\n", CYAN);
            cprint("   ./kernel-sim -q [quantum] -c [number of cpus] -r [number of cores] -t [number of threads]\n", 0);
            cprint("OPTIONS:\n", CYAN);
            cprint("   -q, set scheduler quantum (default 4s)\n", 0);
            cprint("   -c, set number of cups (default 1)\n", 0);
            cprint("   -q, set number of cores per cpu (default 2)\n", 0);
            cprint("   -q, set number of thread per core (default 2)\n", 0);
            return 0;
        default:
            printf("%s\n", "Illegal command arguments");
            return 1;
        }
    }

    /* Inicializar las estructuras */
    cprint("Inicializando estructuras...\n", GREEN);
    if (pthread_mutex_init(&clock_mutex, NULL))
    {
        cprint("Error al iniciar mutex\n", RED);
        return 1;
    }

    if (sem_init(&proc_queue_sem, 0, queue_size))
    {
        cprint("Error al iniciar semaforo\n", RED);
        return 1;
    }

    /* Inicializar machine */
    init_machine(&m, cpus, cores, threads);
    init_queue();
    init_memory();

    /* Lanzar los hilos */
    cprint("Lanzando hilos...\n", GREEN);
    pthread_t clock_thread, pgen_thread, sched_thread, timer_thread;

    cprint("Creando hilo del Clock...\n", GREEN);
    pthread_create(&clock_thread, NULL, (void*)start_clock, NULL);

    cprint("Creando hilo del PG...\n", GREEN);
    // TODO launch loader
    pthread_create(&pgen_thread, NULL, (void*)loader, NULL);

    cprint("Creando hilo del Timer...\n", GREEN);
    pthread_create(&timer_thread, NULL, (void*)start_timer, NULL);

    cprint("Creando hilo del Sched...\n", GREEN);
    pthread_create(&sched_thread, NULL, (void*)start_sched, NULL);

    // Join threads
    pthread_join(clock_thread, NULL);
    pthread_join(pgen_thread, NULL);
    pthread_join(timer_thread, NULL);
    pthread_join(sched_thread, NULL);

    // Free

    return 0;
}
