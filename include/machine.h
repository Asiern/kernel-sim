#ifndef _MACHINE_H
#define _MACHINE_H
#include "types.h"
#include <stdlib.h>

void init_core(core* c, int n_threads);
void init_cpu(cpu* c, int n_cores, int n_threads);
void init_machine(machine* m, int n_cpus, int n_cores, int n_threads);
void runCycle(void);
void runThreadCycle(thread* t);
void loadPCB(int thread_id, pcb* item);
pcb* getPCB(int thread_id);
instruction decodeInstruction(unsigned char* encoded);
int isThreadBusy(int thread_id);
void print_machine();
int getRegister(unsigned char reg);
int getOP(unsigned char op);

#endif