#include "utils.h"

/**
 * @brief Printf with colors!!!
 * @param text
 * @param color
 * @return (void)
 */
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

/**
 * @brief Calcular modulo
 * @param x
 * @param y
 * @return x mod y
 */
int modulo(int x, int y)
{
    return (x % y + y) % y;
}