#include "machine.h"
#include "cpu.h"
#include <stdlib.h>

void init_machine(machine* m, int n_cpus, int n_cores, int n_threads)
{
    int i = 0;
    m->cpus = (cpu*)malloc(n_cpus * sizeof(cpu));
    for (i; i < n_cpus; i++)
        init_cpu(&(m->cpus[i]), n_cores, n_threads);
}