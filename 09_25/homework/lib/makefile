CC = gcc
CFLAGS = -g -Wall
OUTPUT = libfuncs.a
OBJFILES = func1.o func2.o

.PHONY: clean

$(OUTPUT): $(OBJFILES)
	ar rv $(OUTPUT) $(OBJFILES)

%.o: %.c
	$(CC) $(CFLAGS) -I../include -c $< -o $@

clean:
	/bin/rm -f *.o ; /bin/rm -f *.a
