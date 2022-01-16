#include "loader.h"
#include "dirent.h"
#include "globals.h"
#include "physical.h"
#include "process.h"
#include "utils.h"
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pthread_mutex_t queue_mtx;
pthread_mutex_t memory_mtx;
unsigned long last_id;
int freeSpace;

void* loader(void)
{
    DIR* dir;
    struct dirent* ent;
    last_id = 0;
    char line[16];

    if ((dir = opendir("./input")) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            if (validate(ent->d_name) == 1)
                continue;
            printf("[LOADER] Found valid program %s\n", ent->d_name);

            // Open program & Get Size
            int progsize = 0;
            char fileWPath[strlen("./input/") + strlen(ent->d_name)];
            strcpy(fileWPath, "./input/");
            strcat(fileWPath, ent->d_name);
            cprint("[LOADER] Loading file\n", YELLOW);
            FILE* f = fopen(fileWPath, "r");
            if (f == NULL)
            {
                cprint("[ERROR] No se pudo abrir programa\n", RED);
                exit(-1);
            }
            while (fgets(line, sizeof(line), f) != NULL)
                progsize++;

            fclose(f);

            while (1)
            {
                if (isQueueFull() == 0)
                {
                    cprint("[LOADER] Queue full\n", GREEN);
                    sleep(2);
                    continue;
                }
                if (freeSpace < progsize)
                {
                    cprint("[LOADER] Memory full\n", GREEN);
                    sleep(2);
                    continue;
                }
                else
                {
                    pthread_mutex_lock(&queue_mtx);
                    pthread_mutex_lock(&memory_mtx);
                    if (isQueueFull() == 0)
                    {
                        pthread_mutex_unlock(&memory_mtx);
                        pthread_mutex_unlock(&queue_mtx);
                        continue;
                    }
                    break;
                }
            }

            // Load program to memory
            int lineNumber = 0;
            unsigned char *text, *data;
            int lines_text, lines_data;
            int part = 0;
            f = fopen(fileWPath, "r");
            while (fgets(line, sizeof(line), f) != NULL)
            {
                if (lineNumber == 0)
                    NULL;
                if (lineNumber < 4)
                {
                    // Allocate text
                    text = (unsigned char*)malloc(sizeof(unsigned char));
                    text[0] = '\0';
                    // Allocate data
                    data = (unsigned char*)malloc(sizeof(unsigned char));
                    data[0] = '\0';
                }
                else
                {
                    if (part == 0)
                    {
                        lines_text++;
                        text = (unsigned char*)realloc(text, sizeof(unsigned char) * 8 * lines_text + 1);
                        strncat((char*)text, line, sizeof(unsigned char) * 8);
                        if (strcmp(line, "F0000000\n") == 0)
                            part = 1;
                    }
                    else
                    {
                        lines_data++;
                        data = (unsigned char*)realloc(data, sizeof(unsigned char) * 8 * lines_data + 1);
                        strncat((char*)data, line, sizeof(unsigned char) * 8);
                    }
                }
                lineNumber++;
            }
            freeSpace -= progsize * 8 * sizeof(unsigned char);

            // Create PCB
            pcb* p = (pcb*)malloc(sizeof(pcb));
            p->pid = last_id;
            p->status = 1;
            p->mm.code = text;
            p->mm.data = data;
            p->size = progsize - 2;
            p->pc = 0;
            // TODO set pgb
            // p->mm.pgb = ;

            // Add pcb to queue
            printf("[LOADER] Loaded process pid: %ld\n", p->pid);
            addItem(p);
            pthread_mutex_unlock(&memory_mtx);
            pthread_mutex_unlock(&queue_mtx);

            // Increase last id
            last_id++;

            // Close file
            fclose(f);
        }
    }
    else
    {
        cprint("Error input folder not found\n", RED);
        exit(-1);
    }

    cprint("[LOADER] All programs loaded\n", YELLOW);
    for (;;)
        NULL;
}

int validate(const char* filename)
{
    char* ldot = strrchr(filename, '.');
    if (strlen(ldot) == 1)
        return 1;
    if (ldot != NULL)
        return strcmp(ldot + 1, extension);
    return 1;
}
