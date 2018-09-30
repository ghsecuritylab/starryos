#include <stdio.h>
#include <unistd.h>
#include "task.h"
#include "memory.h"
#include "time.h"

static void *test_func(void *arg)
{
	int now;
	void *mem = luban_memory_malloc(1024);

	now = luban_time();
	printf("hello world, mem: %p, time: %d, time_str: %s\n", mem, now, luban_time_str());	
	
	luban_memory_free(mem);

	return NULL;
}

int main(int argc, char **argv)
{
	int i;
	int ret = 0;
	task_init();
	luban_memory_init();

	for (i = 0; i < /*256 * 256*/16; i ++) {
		create_task("test", 4, i % 16, test_func, NULL);
	}


	while(1) {
		ret = run_one_task();
		if (ret != 0) {
			sleep(1);
		}
	}

	task_fini();
	luban_memory_fini();

	return 0;
}
