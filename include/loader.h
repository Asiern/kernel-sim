#include "types.h"

#define extension ".elf"

int last_program_id;

void* loader(void);
int validate(const char* filename);