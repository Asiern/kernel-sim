#ifndef _UTILS_H
#define _UTILS_H

#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define RESET 7

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_RESET "\x1b[0m"

#include <stdio.h>

void cprint(char const *const text, int color)
{
    switch (color)
    {
    case RED:
        printf(COLOR_RED);
        break;
    case GREEN:
        printf(COLOR_GREEN);
        break;
    case YELLOW:
        printf(COLOR_YELLOW);
        break;
    case BLUE:
        printf(COLOR_BLUE);
        break;
    case MAGENTA:
        printf(COLOR_MAGENTA);
        break;
    case CYAN:
        printf(COLOR_CYAN);
        break;
    default:
        break;
    }
    printf(text);
    printf(COLOR_RESET "\n");
}
#endif