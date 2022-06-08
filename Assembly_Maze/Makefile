CC = gcc
CFLAGS=
DFLAGS=
PROGS = maze
DEPS = header.h

all: $(PROGS)

%: %.c $(DEPS)
	$(CC) $(CFLAGS) $(DFLAGS) $< -o $@ -g -Wall header.c

clean:
	rm -f $(PROGS) *.o ~*






