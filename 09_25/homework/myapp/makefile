CC = gcc
CFLAGS = -g -Wall
OUTPUT = main
SOURCE = main.c
OBJFILES = main.o

.PHONY: clean

$(OUTPUT): $(OBJFILES)
	$(CC) -o $(OUTPUT) -L../lib $(OBJFILES) -lfuncs

$(OBJFILES): $(SOURCE)
	$(CC) $(CFLAGS) -c -I../include $(SOURCE) -o $(OBJFILES)

clean:
	/bin/rm -f *.o
