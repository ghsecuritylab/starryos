#include <stdio.h>
#include "task.h"

#define TASK_NAME_MAX	256
#define TASKS_MAX		256
#define PRIORITY_MAX	256
struct task {
	char name[TASK_NAME_MAX];
	task_func func;
	void *arg;
};

int task_indexs[PRIORITY_MAX] = {0};
struct task tasks[PRIORITY_MAX][TASKS_MAX];

int create_task(char *task_name, int task_name_len, int priority, task_func func, void *arg)
{
	struct task *t = &tasks[priority][task_indexs[priority]]; 

	snprintf(t->name, TASK_NAME_MAX, "%s", task_name);
	t->func = func;
	t->arg = arg;

	task_indexs[priority] ++;

	return 0;
}

int delete_task(int task_id)
{
	return 0;
}

int run_task()
{
	int i = 0;
	int j = 0;

	for (i = 0; i < PRIORITY_MAX; i ++) {
		for (j = 0; j < task_indexs[i]; j ++) {
			tasks[i][j].func(tasks[i][j].arg);
		}
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
