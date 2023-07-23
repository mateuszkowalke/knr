CC := gcc
CFLAGS := -Wall -g -o0
OBJS := main.o alloc.o

main: $(OBJS)
	$(CC) $^ -lm -o $@

%.o: %.c
	$(CC) -c ${CFLAGS} $< -o $@

clear:
	rm -rf main *.o
