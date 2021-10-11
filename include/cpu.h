#ifndef _CPU_H
#define _CPU_H
#include "core.h"

typedef struct
{
    core* cores;
} cpu;

void init_cpu(cpu* c, int n_cores, int n_threads);

#endif