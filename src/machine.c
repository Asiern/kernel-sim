#include "machine.h"
#include "globals.h"
#include "physical.h"
#include "process.h"
#include "utils.h"
#include <stdlib.h>

// Instructions
#define LD 1
#define ST 2
#define ADD 3
#define EXIT 4

unsigned int cpus;    /* Número de cpus */
unsigned int cores;   /* Número de cores por cpu */
unsigned int threads; /* Número de hilos de un core */
machine m;            /* Máquina */

int last_thread_id;
int last_core_id;
int last_cpu_id;

/**
 * @brief Initialize core
 * @param c core pointer
 * @param n_threads number of threads per core
 * @return (void)
 */
void init_core(core* c, int n_threads)
{
    c->threads = (thread*)malloc(sizeof(thread) * n_threads);
    c->id = last_core_id;
    for (int i = 0; i < n_threads; i++)
    {
        thread* t = (thread*)malloc(sizeof(thread));
        t->busy = 0;
        t->id = last_thread_id;
        t->process = NULL;
        last_thread_id++;
        c->threads[i] = *t;
    }
}

/**
 * @brief Initialize cpu
 * @param c cpu pointer
 * @param n_cores number of cores per cpu
 * @param n_threads number of threads per core
 * @return (void)
 */
void init_cpu(cpu* c, int n_cores, int n_threads)
{
    int i = 0;
    c->cores = (core*)malloc(sizeof(core) * n_cores);
    c->id = last_cpu_id;
    for (; i < n_cores; i++)
    {
        init_core(&(c->cores[i]), n_threads);
        last_core_id++;
    }
}

/**
 * @brief Initialize machine
 * @param m machine pointer
 * @param n_cpus number of cpus
 * @param n_cores number of cores per cpu
 * @param n_threads number of threads per core
 * @return (void)
 */
void init_machine(machine* m, int n_cpus, int n_cores, int n_threads)
{
    last_thread_id = 0;
    last_core_id = 0;
    last_cpu_id = 0;
    int i = 0;
    m->cpus = (cpu*)malloc(n_cpus * sizeof(cpu));
    for (; i < n_cpus; i++)
    {
        init_cpu(&(m->cpus[i]), n_cores, n_threads);
        last_cpu_id++;
    }
    m->freethreads = n_cpus * n_cores * n_threads;

    print_machine();
}

void runCycle(void)
{
    // print_queue();
    cprint("[MACHINE] Running cycle\n", MAGENTA);
    for (unsigned int i = 0; i < cpus; i++)
    {
        cpu c = m.cpus[i];
        for (unsigned int j = 0; j < cores; j++)
        {
            core r = c.cores[j];
            for (unsigned int k = 0; k < threads; k++)
            {
                thread* t = &(r.threads[k]);
                runThreadCycle(t);
            }
        }
    }
}

void runThreadCycle(thread* t)
{
    // Decode instruction
    if (t->busy == 0)
        return;

    unsigned char* encoded = t->process->mm.code;
    instruction decodedInst = decodeInstruction(encoded + (t->process->pc * 8));
    int address;

    switch (decodedInst.op)
    {
    case LD:
        printf("tid: %d => LD r%d, @%d\n", t->id, decodedInst.reg, decodedInst.addr);
        // Translate src addr
        address = getPhysicalAddress(decodedInst.addr);
        int load = loadData(address);
        // Save value to reg
        t->process->reg[decodedInst.reg] = load;
        // Increase pc
        t->process->pc++;
        break;
    case ST:
        printf("tid: %d => ST r%d, @%d\n", t->id, decodedInst.reg, decodedInst.addr);
        int store = t->process->reg[decodedInst.reg];
        // Translate dst addr
        address = getPhysicalAddress(decodedInst.addr);
        // Save value to mem
        storeData(address, store);
        // Increase pc
        t->process->pc++;
        break;
    case ADD:
        printf("tid: %d => ADD r%d, r%d, r%d\n", t->id, decodedInst.reg, decodedInst.op1, decodedInst.op2);
        int val1 = t->process->reg[decodedInst.op1];
        int val2 = t->process->reg[decodedInst.op2];
        t->process->reg[decodedInst.reg] = val1 + val2;
        // Increase pc
        t->process->pc++;
        break;
    case EXIT:
        printf("tid: %d => EXIT\n", t->id);
        t->busy = 0;
        t->process = NULL;
        t->ir = 0;
        loadPCB(t->id, pop_queue());
        break;
    }
}

void loadPCB(int thread_id, pcb* item)
{
    for (unsigned int i = 0; i < cpus; i++)
        for (unsigned int j = 0; j < cores; j++)
            for (unsigned int k = 0; k < threads; k++)
            {
                if (m.cpus[i].cores[j].threads[k].id == thread_id)
                {
                    m.cpus[i].cores[j].threads[k].process = item;
                    m.cpus[i].cores[j].threads[k].busy = 1;
                    return;
                }
            }

    m.freethreads--;
}

pcb* getPCB(int thread_id)
{
    for (unsigned int i = 0; i < cpus; i++)
        for (unsigned int j = 0; j < cores; j++)
            for (unsigned int k = 0; k < threads; k++)
            {
                if (m.cpus[i].cores[j].threads[k].id == thread_id)
                {
                    m.cpus[i].cores[j].threads[k].busy = 0;
                    return m.cpus[i].cores[j].threads[k].process;
                }
            }

    m.freethreads++;
    return NULL;
}

instruction decodeInstruction(unsigned char* encoded)
{
    instruction decoded;
    decoded.op = getOP(encoded[0]);
    if (decoded.op == ADD)
    {
        // Get operands rgs
        decoded.op1 = getRegister(encoded[2]);
        decoded.op2 = getRegister(encoded[3]);
    }
    else
    {
        // Get address
        unsigned char* addr = (unsigned char*)malloc(sizeof(unsigned char) * 6);
        for (int i = 0; i < 6; i++)
            addr[i] = encoded[2 + i];
        decoded.addr = (int)strtol((char*)addr, NULL, 16);

        free(addr);
    }
    decoded.reg = getRegister(encoded[1]);
    return decoded;
}

int isThreadBusy(int thread_id)
{
    thread t;
    for (unsigned int i = 0; i < cpus; i++)
    {
        cpu c = m.cpus[i];
        for (unsigned int j = 0; j < cores; j++)
        {
            core r = c.cores[j];
            for (unsigned int k = 0; k < threads; k++)
            {
                t = r.threads[k];
                if (t.id == thread_id)
                    return t.busy;
            }
        }
    }
    return -1;
}

void print_machine()
{
    printf("\n[ == MACHINE == ]\n\n");
    for (unsigned int i = 0; i < cpus; i++)
    {
        printf("CPU id:%d\n", m.cpus[i].id);
        for (unsigned int j = 0; j < cores; j++)
        {
            printf("\tCORE id:%d\n", m.cpus[i].cores[j].id);
            for (unsigned int k = 0; k < threads; k++)
            {

                thread t = m.cpus[i].cores[j].threads[k];
                printf("\t\tTid: %d\n", t.id);
                printf("\t\tBusy: %d\n\n", t.busy);
                // printf("\t\tPID: %ld\n", t.process->pid);
            }
        }
    }
}

int getRegister(unsigned char reg)
{
    // printf("Get register %c\n", reg);
    int rg;
    switch (reg)
    {
    case '0':
        rg = 0;
        break;
    case '1':
        rg = 1;
        break;
    case '2':
        rg = 2;
        break;
    case '3':
        rg = 3;
        break;
    case '4':
        rg = 4;
        break;
    case '5':
        rg = 5;
        break;
    case '6':
        rg = 6;
        break;
    case '7':
        rg = 7;
        break;
    case '8':
        rg = 8;
        break;
    case '9':
        rg = 9;
        break;
    case 'A':
        rg = 10;
        break;
    case 'B':
        rg = 11;
        break;
    case 'C':
        rg = 12;
        break;
    case 'D':
        rg = 13;
        break;
    case 'E':
        rg = 14;
        break;
    case 'F':
        rg = 15;
        break;
    default:
        rg = -1;
        break;
    }
    return rg;
}

int getOP(unsigned char op)
{
    // printf("Get OP %c\n", op);
    int o;
    switch (op)
    {
    case '0':
        o = LD;
        break;
    case '1':
        o = ST;
        break;
    case '2':
        o = ADD;
        break;
    case 'F':
        o = EXIT;
        break;
    default:
        o = -1;
        break;
    }
    return o;
}