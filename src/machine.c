#include "machine.h"

void init_thread(thread* t, int id)
{
    t = (thread*)malloc(sizeof(thread));
    t->busy = 0;
    t->id = id;
    t->process = NULL;
}

void init_core(core* c, int n_threads)
{
    int i = 0;
    c->threads = (thread*)malloc(sizeof(thread) * n_threads);
    for (; i < n_threads; i++)
        init_thread(&(c->threads[i]), i);
}

void init_cpu(cpu* c, int n_cores, int n_threads)
{
    int i = 0;
    c->cores = (core*)malloc(sizeof(core) * n_cores);
    for (; i < n_cores; i++)
        init_core(&(c->cores[i]), n_threads);
}

void init_machine(machine* m, int n_cpus, int n_cores, int n_threads)
{
    int i = 0;
    m->cpus = (cpu*)malloc(n_cpus * sizeof(cpu));
    for (; i < n_cpus; i++)
        init_cpu(&(m->cpus[i]), n_cores, n_threads);
    /*m->usage = calloc(n_threads * n_cores * n_cpus, sizeof(unsigned int));*/
}

/*int loadPCB(machine* m, pcb* pcb)
{
    return 0;
}*/