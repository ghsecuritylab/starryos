#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>


int luban_open(char *path, int flag)
{
	return open(path, flag);
}

int luban_read(int fd, char *buf, int buf_size)
{
	return read(fd, buf, buf_size);
}

int luban_write(int fd, char *buf, int buf_size)
{
	return write(fd, buf, buf_size);
}

int luban_close(int fd)
{
	return close(fd);
}
