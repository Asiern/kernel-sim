#ifndef _MACHINE_H
#define _MACHINE_H

#include "process.h"
typedef struct
{
    int id;
    int busy;
    pcb* process;
} thread;

void init_thread(thread* t, int id);

typedef struct
{
    thread* threads;
} core;

void init_core(core* c, int n_threads);

typedef struct
{
    core* cores;
} cpu;

void init_cpu(cpu* c, int n_cores, int n_threads);

typedef struct
{
    cpu* cpus;
} machine;

void init_machine(machine* m, int n_cpus, int n_cores, int n_threads);

int loadPCB(machine* m, pcb* pcb);
#endif