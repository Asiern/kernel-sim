#include "process.h"

unsigned long last_id;

pcb create_pcb(void)
{
    pcb p;
    p.pid = last_id + 1;
    p.lifetime = rand();
    return p;
}