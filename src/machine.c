#include "machine.h"
#include "cpu.h"
#include <stdlib.h>

void init_machine(machine* m, int n_cpus, int n_cores, int n_threads)
{
    m->cpus = (cpu*)malloc(n_cpus * sizeof(cpu));
    for (int i = 0; i < n_cpus; i++)
        init_cpu(&(m->cpus[i]), n_cores, n_threads);
}