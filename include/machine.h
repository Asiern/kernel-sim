#ifndef _MACHINE_H
#define _MACHINE_H
#include "types.h"
#include <stdlib.h>

void init_thread(thread* t, int id);
void init_core(core* c, int n_threads);
void init_cpu(cpu* c, int n_cores, int n_threads);
void init_machine(machine* m, int n_cpus, int n_cores, int n_threads);
int loadPCB(machine* m, pcb* pcb);

#endif