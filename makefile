CC=gcc
EXEC=listomatic
OPT=-Wall -std=c99

all: $(EXEC)

$(EXEC): *.o
	$(CC) $(OPT) *.o -o $(EXEC)

.c.o:
	$(CC) $(OPT) -c *.c

clean:
	rm -f *.o $(EXEC) a.out
