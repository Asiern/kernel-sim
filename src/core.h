#ifndef _CORE_H

#define _CORE_H
#include "thread.h"

struct _core
{
    thread *t;
};
typedef struct _core core;

core *init_core()
{
    return NULL;
}
#endif