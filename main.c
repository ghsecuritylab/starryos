#include <stdio.h>
#include <unistd.h>
#include "task.h"

static void *test_func(void *arg)
{
	printf("hello world\n");	

	return NULL;
}

int main(int argc, char **argv)
{
	int i;
	int ret = 0;
	task_init();

	for (i = 0; i < 256 * 256; i ++) {
		create_task("test", 4, i % 16, test_func, NULL);
	}


	while(1) {
		ret = run_one_task();
		if (ret != 0) {
			sleep(1);
		}
	}

	task_fini();

	return 0;
}
