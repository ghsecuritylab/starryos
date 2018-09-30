#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LUBAN_MEM_SIZE 1024*1024*128

#define GLOBAL_MEMORY_LOG_MIN	4
#define GLOBAL_MEMORY_LOG_MAX	14	

#define GLOBAL_MEMORY_SIZE		128

struct luban_memory {
	void *memory[GLOBAL_MEMORY_SIZE];
	int memory_size;
};

static struct luban_memory memorys[GLOBAL_MEMORY_LOG_MAX] = {NULL};
	

static int global_index = 0;

int find_luban_memory_index(int size)
{
	int ret = -1;
	int i;

	for (i = GLOBAL_MEMORY_LOG_MIN; i < GLOBAL_MEMORY_LOG_MAX; i ++) {
		if (size < (pow(2,i))) {
			ret = i;
			break;
		}
	}

	return ret;
}

void *luban_memory_malloc(int size)
{
	void *memory = NULL;
	int index = 0;


	index = find_luban_memory_index(size);
	if (index == -1) {
		goto exit;
	}

	memory = memorys[index].memory[0];
	memorys[index].memory_size --;

	memmove(&memorys[index].memory[0], &memorys[index].memory[1], 
			memorys[index].memory_size * sizeof(void *));

	if (memorys[index].memory_size < GLOBAL_MEMORY_SIZE / 2) {
		//TODO;，把剩余的内存槽分配完
	}

exit:

	return memory;
}

void luban_memory_free(void *mem)
{
	free(mem);
}

int luban_memory_init()
{
	int i, j;


	for (i = GLOBAL_MEMORY_LOG_MIN; i < GLOBAL_MEMORY_LOG_MAX; i ++) {
		for (j = 0; j < GLOBAL_MEMORY_SIZE; j ++) {
			memorys[i].memory[j] = malloc(pow(2,i));
			if (memorys[i].memory[j] == NULL) {
				break;
			} else {
			}
		}

		memorys[i].memory_size = GLOBAL_MEMORY_SIZE;
	}


	return 0;
}

void luban_memory_fini()
{

}


