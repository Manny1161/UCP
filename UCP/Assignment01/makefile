CC = gcc
CFLAGS = -Wall -pedantic -ansi -g
OBJ = main.o map.o input.o terminal.o random.o
EXEC = snake

ifdef UNBEATABLE
CFLAGS += -D UNBEATABLE
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -g -o $(EXEC)

main.o: main.c map.h input.h terminal.h random.h
	$(CC) $(CFLAGS) -c main.c

map.o: map.c map.h
	$(CC) $(CFLAGS) -c map.c

input.o: input.c input.h terminal.h map.h
	$(CC) $(CFLAGS) -c input.c

terminal.o: terminal.c terminal.h
	$(CC) $(CFLAGS) -c terminal.c

random.o: random.c random.h
	$(CC) $(CFLAGS) -c random.c

clean:
	rm -f $(EXEC) $(OBJ)
