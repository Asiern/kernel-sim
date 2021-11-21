#ifndef _TYPES_H
#define _TYPES_H

typedef struct
{
    long pid;
    float lifetime;
} pcb;

typedef struct
{
    int id;
    int busy;
    pcb* process;
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