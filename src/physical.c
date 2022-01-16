#include "physical.h"
#include "globals.h"
#include <stdlib.h>

unsigned char* Memory;
int freeSpace;

/**
 * @brief Initialize memory
 */
void init_memory(void)
{
    // Physical memory
    Memory = (unsigned char*)malloc(mem_size);

    // Set free space
    freeSpace = mem_size;
}

/**
 * @brief Check memory if there is enough space
 * @param size
 * @return 0 <=> free space; 1 <=> no free space
 */
int checkMemorySpace(int size)
{
    return freeSpace < size;
}

/**
 * @brief Load program to memory
 */
void loadProgram()
{
}

/**
 * @brief Store data to memory address
 * @param addr Memory address
 * @param data Data to store
 */
void storeData(int addr, int data)
{
    if (addr != 1)
        Memory[addr] = data;
}

int loadData(int addr)
{
    return Memory[addr];
}

unsigned char getVirtualAddress(int address)
{
}

int getPhysicalAddress(unsigned char address)
{
}