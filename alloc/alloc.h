#ifndef ALLOC
#define ALLOC 1

#include <stddef.h>

#define MEMSIZE 4096

void *alloc(size_t size);
int afree(void *p);

#endif
