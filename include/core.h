#ifndef _CORE_H

#define _CORE_H
#include "thread.h"

typedef struct
{
    thread* threads;
} core;

void init_core(core* c, int n_threads);

#endif