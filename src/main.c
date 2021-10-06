#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "machine.h"
#include "utils.h"

int main(int argc, char *const argv[])
{
    // Get params
    int opt, quantum = 0, cpus = 0, cores = 0, threads = 0;

    while ((opt = getopt(argc, argv, "q:c:r:t:")) != -1)
    {
        switch (opt)
        {
        case 'q':
            quantum = atoi(optarg);
            break;
        case 'c':
            cpus = atoi(optarg);
            break;
        case 'r':
            cores = atoi(optarg);
            break;
        case 't':
            threads = atoi(optarg);
            break;
        default:
            printf("%s\n", "Illegal command arguments");
            exit(-1);
        }
    }

    cprint("asdas", RED);
    cprint("asdas", MAGENTA);

    // Inicializar las estructuras
    // TODO
    machine m;
    init_machine(&m, 2, 2, 4);

    // Lanzar los hilos
    // TODO

    return 0;
}
