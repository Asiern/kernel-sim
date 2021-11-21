#ifndef _CLOCK_H
#define _CLOCK_H

#include <pthread.h>

#include "globals.h"
#include "machine.h"
#include "timer.h"
#include "types.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void* start_clock(void);

#endif