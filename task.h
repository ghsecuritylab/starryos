#ifndef __LUBAN_TASK_H
#define __LUBAN_TASK_H

typedef void *(*task_func)(void *task_args);

int create_task(char *task_name, int task_name_len, int priority, task_func func, void *arg);
int delete_task(int task_id);
int run_task();
int task_init();
int task_fini();

#endif

