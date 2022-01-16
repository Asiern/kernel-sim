#ifndef PHYSICAL_H
#define PHYSICAL_H

#define bus_size 23       // bits
#define word_size 4 * 8   // Bits
#define page_size 256 * 8 // Bits
#define offset 4          // Bits
#define frame 20          // Bits
#define mem_size 1 << 24
#define kernel_start_add 0x0
#define kernel_end_add 0x3FFFFF
#define USER_RESERVED 1
#define KERNEL_RESERVED 2

void init_memory(void);
unsigned char readPMemory(unsigned char* address);
int checkMemorySpace(int size);
void storeData(int addr, int data);
int loadData(int addr);
int getPhysicalAddress(int address);

#endif