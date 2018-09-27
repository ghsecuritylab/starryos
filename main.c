#include <stdio.h>
#include "task.h"

static void *test_func(void *arg)
{
	printf("hello world\n\n");	

	return NULL;
}

int main(int argc, char **argv)
{
	task_init();

	create_task("test", 4, test_func, NULL);
	run_task();

	task_fini();

	return 0;
}
