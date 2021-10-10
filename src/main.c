#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "defines.h"
#include "utils.h"
#include "machine.c"
#include "clock.c"
#include "process.h"
#include "procqueue.c"

pthread_mutex_t clock_mutex;

int main(int argc, char *const argv[])
{
    // Get params
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

    //Inicializar las estructuras
    cprint("Inicializando estructuras...", BLUE);
    if (pthread_mutex_init(&clock_mutex, NULL))
    {
        cprint("Error al iniciar mutex", RED);
        exit(-1);
    }

    // TODO
    machine m;
    init_machine(&m, cpus, cores, threads);

    queue q;
    init_queue(&q, quantum);

    // Lanzar los hilos
    cprint("Lanzando hilos...", BLUE);
    pthread_t clock_thread, pgen_thread, sched_thread, timer_thread;
    // pthread_create(&clock_thread, NULL, (void *)clk, NULL);
    // TODO
    //Clock

    //Timer
    //PGen
    //Sched
    // pthread_join(clock_thread, NULL);

    return 0;
}
