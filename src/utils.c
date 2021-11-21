#include "utils.h"

/* GLOBALS */
machine m;
extern unsigned int cpus;
extern unsigned int cores;
extern unsigned int threads;

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
    printf(COLOR_RESET);
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

/**
int getThreadPos(int cpu, int core, int thread)
{
    int nThreadsCpu = cores * cpus * threads;
    int nThreadsCore = cpus * threads;
    return cpu * nThreadsCpu + core * nThreadsCore + thread;
}*/

/**
 * @brief Print machine usage
 * @param (void)
 * @return (void)
 */
/**
void printUsage(void)
{
    int nThreadsCpu = cores * cpus * threads;
    int nThreadsCore = cpus * threads;
    unsigned int i, j, k;
    for (i = 0; i < cpus; i++)
    {
        int used = 0;
        for (j = 0; j < cores; j++)
        {
            for (k = 0; k < threads; k++)
            {
                if (m.usage[getThreadPos(i, j, k)] == 1)
                    used++;
            }
            printf("CORE %d usage %f\n", i, nThreadsCore / used);
        }
        printf("");
    }
}
*/