#include "utils.h"

void cprint(char const* const text, int color)
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
    printf("%s", text);
    printf(COLOR_RESET "\n");
}
