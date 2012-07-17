CC=clang
CFLAGS= -Wall
LD=ld
LDFLAGS=

default: fprobe

fprobe: 
	$(CC) $(CFLAGS) -o fprobe src/fprobe.c

clean: 
	rm -f fprobe 
	rm -rf *.o
