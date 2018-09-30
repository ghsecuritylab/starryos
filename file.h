#ifndef __LUBAN_FILE_H
#define __LUBAN_FILE_H

int luban_open(char *path, int flag);
int luban_read(int fd, char *buf, int buf_size);
int luban_write(int fd, char *buf, int buf_size);
int luban_close(int fd);

#endif

