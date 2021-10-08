#ifndef _CLOCK_H
#define _CLOCK_H

#include <pthread.h>

#include "defines.h"
#include "utils.h"

void clk(void)
{
    while (1)
    {
        cprint("Clock", GREEN);
    }
}
#endif