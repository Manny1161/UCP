CC = gcc
CFLAGS = -Wall -pedantic -ansi -g
OBJ = life.o table.o
EXEC = life

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -g -o $(EXEC)

life.o: life.c table.h
	$(CC) $(CFLAGS) -c life.c

table.o: table.c table.h
	$(CC) $(CFLAGS) -c table.c

clean: 
	rm -f $(EXEC) $(OBJ)