#include "alloc.h"

char mem[MEMSIZE];
char *memp = mem;

void *alloc(size_t size) {
    if (memp + size > mem + MEMSIZE) {
        return NULL;
    }
    memp += size;
    return memp - size;
}

int afree(void *p) {
    if (!((char *)p >= mem && (char *)p <= mem + MEMSIZE)) {
        return 1;
    }
    memp = p;
    return 0;
}
