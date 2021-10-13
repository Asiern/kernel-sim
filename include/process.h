#ifndef _PCB_H
#define _PCB_H

#include <stdlib.h>

extern long last_id;

typedef struct
{
    long pid;
    float lifetime;
} pcb;

pcb create_pcb(void);

#endif
