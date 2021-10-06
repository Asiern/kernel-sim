#ifndef _CPU_H
#define _CPU_H
#include "core.h"

struct _cpu
{
    core *c;
};
typedef struct _cpu cpu;

cpu *init_cpu(int n_cores)
{
    cpu c;
    c.c = (core *)malloc(sizeof(core) * n_cores);
    for (int i = 0; i < n_cores; i++)
        c.c->t = init_core();
    return &c;
}
#endif