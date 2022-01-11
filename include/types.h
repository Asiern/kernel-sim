#ifndef _TYPES_H
#define _TYPES_H

typedef struct
{
    int code;
    int data;
    int pgb;
} mm;

typedef struct
{
    // TODO add tlb definition
} mmu;
typedef struct
{
    long pid;
    float lifetime;
    mm mm;
    int status;
    int reg[16];
    int ptbr;
    int pc;
    int size;
} pcb;

typedef struct
{
    int id;
    int busy;
    pcb* process;
    int pc;
    int ir;
} thread;

typedef struct
{
    thread* threads;
} core;

typedef struct
{
    core* cores;
} cpu;

typedef struct
{
    cpu* cpus;
    /*unsigned int* usage;*/
} machine;

typedef struct
{
    pcb* queue;
    int first;
    int last;
} queue;

#endif