CC=gcc
CFLAGS=-O3 -ggdb
LIBS=-lm

DEPS = modular_inverse.h test.h
OBJ = main.o modular_inverse.o test.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test_work: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o *~ core $(INCDIR)/*~ 