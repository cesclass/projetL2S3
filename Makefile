#makefile pile dynamique
CC = gcc
CFLAGS =-Wall -g

EXECS = builds/exe

all : $(EXECS)

clean :
	rm -rf $(EXECS) objects/*.o

builds/exe : objects/main.o objects/argument_read.o
	$(CC) -o $@ $^ $(CFLAGS)

objects/main.o : headers/argument_read.h
objects/argument_read.o : headers/argument_read.h

objects/%.o : sources/%.c
	$(CC) -c $< -o $@ $(CFLAGS)
