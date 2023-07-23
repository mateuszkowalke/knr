CC := gcc
CFLAGS := -Wall -g -o0
OBJS := calculator.o calculator_buffer.o calculator_stack.o atof.o

calculator: $(OBJS)
	$(CC) $^ -lm -o $@

%.o: %.c
	$(CC) -c ${CFLAGS} $< -o $@

clear:
	rm -rf calculator *.o
