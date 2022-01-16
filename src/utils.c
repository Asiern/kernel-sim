#include "utils.h"

/**
 * @brief Printf with colors!!!
 * @param text text to print
 * @param color text color
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
    printf(COLOR_RESET);
}

/**
 * @brief Calculate x mod y
 * @param x
 * @param y
 * @return x mod y
 */
int modulo(int x, int y)
{
    return (x % y + y) % y;
}

unsigned char* ustrcat(unsigned char* dest, const unsigned char* src)
{
    unsigned int length_1 = 0;
    unsigned int length_2 = 0;
    // find the end of the first unsigned char string
    for (; dest[length_1] != '\0'; length_1++)
        ;
    // input unsigned chars into the string from that position to the end
    for (; src[length_2] != '\0'; length_2++)
        dest[length_1 + length_2] = src[length_2];
    // place a NULL terminating character at the end
    dest[length_1 + length_2] = '\0';
    return dest;
}