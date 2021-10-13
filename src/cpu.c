#include "cpu.h"
#include "core.h"
#include <stdlib.h>

void init_cpu(cpu* c, int n_cores, int n_threads)
{
    int i = 0;
    c->cores = (core*)malloc(sizeof(core) * n_cores);
    for (i; i < n_cores; i++)
        init_core(&(c->cores[i]), n_threads);
}