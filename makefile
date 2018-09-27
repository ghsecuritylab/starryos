SHELL=/bin/sh
PREFIX=/usr/local/

CFLAGS+= 

LDFLAGS+=

all: luban

LIB_OBJS = task.o main.o

luban: $(LIB_OBJS)
	${CC} ${CFLAGS} $(LIB_OBJS) -o main ${LDFLAGS}

distclean: clean
clean:
	rm -f *.o *.core main


