#ifndef _TIMER_H
#define _TIMER_H

typedef struct
{

} timer;

void* start_timer(void* params);

typedef struct
{
    timer* t;
} start_timer_params;
#endif