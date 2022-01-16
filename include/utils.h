#ifndef _UTILS_H
#define _UTILS_H

#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_RESET "\x1b[0m"

#include "globals.h"
#include <stdio.h>

void cprint(char const* const text, int color);
int modulo(int x, int y);
unsigned char* ustrcat(unsigned char* dest, const unsigned char* src);
#endif