CC=gcc
CFLAGS=-O3 -ggdb
LIBS=-lm

DEPS = fourth_roots.h
OBJ = main.o test.o fourth_roots.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test_work: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o *~ core $(INCDIR)/*~ 