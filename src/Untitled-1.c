void* load(void* pq)
{
    int i;
    int IDpcb = 1;
    char programa[11] = "prog000.elf";
    char sigProg[11];

    FILE f;
    int count_lines = 0;
    printMemory(physicalmemory);
    while (f = fopen(programa, "r"))
    {
        printf("programa: %s\n", programa);

        int linesText = 0;
        int linesData = 0;
        char text[100];
        char data[100];
        int iniText;
        char iniData[6];
        int iniData2;
        char cadena[100];
        int textArray[LINESMAX];
        int dataArray[LINESMAX];

        int PC = 0;
        fgets(text, 100, f);
        iniText = 0;

        fgets(data, 100, f);
        strncpy(iniData, data + 6, 6);
        iniData2 = (int)strtol(iniData, NULL, 16);

        i = 0;
        int cadenaInt;
        while (PC != iniData2)
        {
            fgets(cadena, 100, f);
            cadenaInt = (int)strtol(cadena, NULL, 16);
            textArray[i] = cadenaInt;
            i++;
            PC += 4;
            linesText++;
        }

        i = 0;
        while (fgets(cadena, 100, f) != NULL)
        {
            cadenaInt = (int)strtol(cadena, NULL, 16);
            dataArray[i] = cadenaInt;
            i++;
            linesData++;
        }

        int numPaginas;
        if ((linesData + linesText) % 64 != 0)
        {
            numPaginas = (linesData + linesText) / 64 + 1;
        }
        else
        {
            numPaginas = (linesData + linesText) / 64;
        }
        int PTBR = escribirDatosMemoria(physicalmemory, textArray, linesText, dataArray, linesData, numPaginas);

        fclose(f);
        strcpy(sigProg, "prog");
        if (siguienteProg(programa, sigProg) == 1)
            break;
        strcpy(programa, sigProg);

        MM* mm = createMM(linesText, linesData, PTBR);
        int prioridad = crearNumPrioridad();
        PCB* pcb = crearPCB(IDpcb, linesText, prioridad, mm, PTBR, numPaginas);

        int sleepSeg = ((rand() % TIEMPO_EXPIRACION) + 1);
        pthread_mutex_lock(&mutexProcesos);
        addCola(queuesstruct, pcb);
        memoria.proceso = 1;
        pthread_mutex_unlock(&mutexProcesos);
        IDpcb++;
        sleep(sleepSeg);
    }
    printf("Ya no quedan programas para ejecutar\n");
}