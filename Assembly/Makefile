CC = gcc
CFLAGS=
DFLAGS=
PROGS = program_4
DEPS = header.h
LDFLAGS =
all: $(PROGS)

%: %.c $(DEPS)
	$(CC) $(CFLAGS) $(DFLAGS) $(LDFLAGS) $< -o $@ -g -Wall header.c -lm
clean:
	rm -f $(PROGS) *.o ~*

