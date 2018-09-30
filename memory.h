#ifndef __LUBAN_MEMMORY_H
#define __LUBAN_MEMMORY_H

void *luban_memory_malloc(int size);
void luban_memory_free(void *mem);

int luban_memory_init();
void luban_memory_fini();

#endif

