#include <stdio.h>
#include "task.h"

struct task {
	char name[256];
	task_func func;
	void *arg;
};

int task_index = 0;
struct task tasks[256];

int create_task(char *task_name, int task_name_len, task_func func, void *arg)
{
	snprintf(tasks[task_index].name, 256, "%s", task_name);
	tasks[task_index].func = func;
	tasks[task_index].arg = arg;
	task_index ++;

	return 0;
}

int delete_task(int task_id)
{
	return 0;
}

int run_task()
{
	int i = 0;
	for (i = 0; i < task_index; i ++) {
		tasks[i].func(tasks[i].arg);
	}
	return 0;
}

int task_init()
{
	return 0;
}

int task_fini()
{
	return 0;
}
