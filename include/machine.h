#ifndef _MACHINE_H
#define _MACHINE_H

#include "cpu.h"

typedef struct
{
    cpu *cpus;
} machine;

void init_machine(machine *m, int n_cpus, int n_cores, int n_threads);
#endif