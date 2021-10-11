#ifndef _PCB_H
#define _PCB_H

#include <stdlib.h>

// #include "rbtree.h"

extern long last_id;

typedef struct
{
    long pid;
    float lifetime;
} pcb;

inline pcb create_pcb(void)
{
    pcb p;
    p.pid = last_id + 1;
    p.lifetime = rand();
    return p;
}

#endif
