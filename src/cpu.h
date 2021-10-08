#ifndef _CPU_H
#define _CPU_H
#include "core.h"

typedef struct
{
    core *cores;
} cpu;

void init_cpu(cpu *c, int n_cores, int n_threads)
{
    c->cores = (core *)malloc(sizeof(core) * n_cores);
    for (int i = 0; i < n_cores; i++)
        init_core(&(c->cores[i]), n_threads);
}
#endif