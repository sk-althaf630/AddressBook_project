OBJ := $(patsubst %.c, %.o, $(wildcard *.c))

apc: $(OBJ)
	gcc -o $@ $^
clean:
	rm *apc *.o