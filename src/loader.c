#include "loader.h"
#include "dirent.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* loader(void)
{
    DIR* dir;
    struct dirent* ent;

    if ((dir = opendir("./input")) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            // TODO Validate entry
            if (validate(ent->d_name) == 1)
                continue;
            printf("Found valid program %s\n", ent->d_name);

            // TODO Compare entry ID with latest program id
            if (0 == 0)
            {
                // Open program
                FILE* f = fopen(ent->d_name, "r");
            }
        }
    }
    else
    {
        cprint("Error input folder not found\n", RED);
        exit(-1);
    }
}

int validate(const char* filename)
{
    char* ldot = strrchr(filename, '.');
    if (strlen(ldot) == 1)
        return 1;
    if (ldot != NULL)
        return strcmp(ldot + 1, ".elf");
    return 1;
}