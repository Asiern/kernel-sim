#ifndef _MACHINE_H
#define _MACHINE_H

#include "cpu.h"

struct _machine
{
    cpu *cpus;
};
typedef struct _machine machine;

void init_machine(machine *m, int n_cpus, int n_cores, int n_threads)
{
    m->cpus = (cpu *)malloc(n_cpus * sizeof(cpu));
    for (int i = 0; i < n_cpus; i++)
        m->cpus = init_cpu(n_cores);
}
#endif