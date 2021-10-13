#ifndef _PCB_H
#define _PCB_H

#include "globals.h"
#include <stdlib.h>

typedef struct
{
    long pid;
    float lifetime;
} pcb;

pcb create_pcb(void);

#endif
