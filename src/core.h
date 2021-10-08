#ifndef _CORE_H

#define _CORE_H
#include "thread.h"

typedef struct
{
    thread *threads;
} core;

void init_core(core *c, int n_threads)
{
    c->threads = (thread *)malloc(sizeof(thread) * n_threads);
    for (int i = 0; i < n_threads; i++)
        init_thread(&(c->threads[i]));
}

#endif