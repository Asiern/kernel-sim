#ifndef _TYPES_H
#define _TYPES_H

typedef struct
{
    int op;
    int reg;
    int op1;
    int op2;
    int addr;
} instruction;

typedef struct
{
    unsigned char* code;
    unsigned char* data;
    int pgb;
} mm;

typedef struct
{
    unsigned char* tlb;
} mmu;

typedef struct
{
    long pid;
    mm mm;
    int status; // Status 0 => finished; 1 => unfinished
    int reg[16];
    int ptbr;
    int pc;
    int size;
} pcb;

typedef struct
{
    int id;
    int busy; // O not busy; 1 busy
    pcb* process;
    int ir;
} thread;

typedef struct
{
    thread* threads;
    int id;
} core;

typedef struct
{
    core* cores;
    int id;
} cpu;

typedef struct
{
    cpu* cpus;
    int freethreads;
} machine;

struct queue_node
{
    pcb* item;
    struct queue_node* next;
};
typedef struct queue_node queue_node;

typedef struct
{
    queue_node* first;
    queue_node* last;
    int count;
} queue;

#endif