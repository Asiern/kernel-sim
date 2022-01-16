#ifndef _PCB_H
#define _PCB_H

#include "globals.h"
#include "machine.h"
#include "types.h"
#include "utils.h"
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

void init_queue(void);
void addItem(pcb* item);
pcb* pop_queue(void);
int isQueueFull(void);
pcb* replaceItem(pcb* item);
void print_queue();

#endif
