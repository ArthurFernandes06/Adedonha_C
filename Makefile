CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = main.o interface.o estrutura_de_dados.o
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c interface.h estrutura_de_dados.h
	$(CC) $(CFLAGS) -c main.c

interface.o: interface.c interface.h
	$(CC) $(CFLAGS) -c interface.c

estrutura_de_dados.o: estrutura_de_dados.c estrutura_de_dados.h
	$(CC) $(CFLAGS) -c estrutura_de_dados.c

clean:
	rm -f *.o $(EXEC)