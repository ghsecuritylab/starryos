#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "task.h"
#include "memory.h"
#include "time.h"
#include "file.h"

static int test_read_file(char *path, char *buf, int buf_size)
{
	int fd = 0;
	int ret = 0;

	fd = luban_open(path, O_RDWR);
	if (fd <= 0) {
		goto exit;
	}

	ret = luban_read(fd, buf, buf_size);
	if (ret <= 0) {
		goto exit;
	}

	luban_close(fd);

exit:

	return ret;
}

static void *test_func(void *arg)
{
	int now;
	char path[128]="test.txt";
	void *mem = luban_memory_malloc(1024);

	memset(mem, 0, 1024);

	test_read_file(path, mem, 1024);
	now = luban_time();
	printf("hello world, mem: %p, time: %d, time_str: %s\n", mem, now, luban_time_str());	
	printf("read file content: %s\n", mem);
	
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
