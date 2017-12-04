
CC = gcc
CFLAGS = -g -Wall
OUTPUT = main
OBJ = main.o func1.o func2.o
FUNCTIONS = func1.o func2.o

.PHONY: clean

$(OUTPUT): $(OBJ) libfuncs.a
	$(CC) $(CFLAGS) main.c -L. -lfuncs -o $(OUTPUT)

#main.o: main.c main.h
#	$(CC) $(CFLAGS) -c main.c

libfuncs.a: $(FUNCTIONS)
	ar rv libfuncs.a $(FUNCTIONS)

%o:%c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o $(OUTPUT)

#func1.o: func1.c
#	$(CC) $(CFLAGS) -c func1.c

#func2.o: func2.c
#	$(CC) $(CFLAGS) -c func2.c
