#include "core.h"

void init_core(core *c, int n_threads)
{
    c->threads = (thread *)malloc(sizeof(thread) * n_threads);
    for (int i = 0; i < n_threads; i++)
        init_thread(&(c->threads[i]));
}