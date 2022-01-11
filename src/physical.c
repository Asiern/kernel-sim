#include "physical.h"
#include "globals.h"
#include <stdlib.h>

unsigned char* Memory;

void init_memory(void)
{
    // Physical memory
    Memory = (unsigned char*)malloc(mem_size);

    // TODO Create Page table

    // TODO Copy page table to Kernel reserved mem
}
