CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = main.o interface.o jogadas.o
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c interface.h jogadas.h
	$(CC) $(CFLAGS) -c main.c

interface.o: interface.c interface.h
	$(CC) $(CFLAGS) -c interface.c

jogadas.o: jogadas.c jogadas.h
	$(CC) $(CFLAGS) -c jogadas.c

clean:
	rm -f *.o $(EXEC)