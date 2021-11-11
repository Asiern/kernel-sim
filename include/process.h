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
typedef struct
{
    pcb* pcb;
} start_pcb_params;

void* start_pcb(void* params);

#endif
