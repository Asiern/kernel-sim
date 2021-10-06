#ifndef _PCB_H
#define _PCB_H
struct _pcb
{
    long pid;
    float lifetime;
};
typedef struct _pcb pcb;
#endif

#ifndef _QUEUE_H
#define _QUEUE_H
struct _queue
{
    pcb *queue;
    int number;
};
typedef struct _queue queue;
#endif