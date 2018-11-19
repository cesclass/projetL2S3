#makefile pile dynamique
CC = gcc
CFLAGS =-Wall -g

EXECS = 				\
	build/hanoi 		\
	build/hanoi_pile

all : $(EXECS)

clean :
	rm -rf $(EXECS) obj/*.o

build/hanoi : obj/hanoi.o obj/pile.o
	$(CC) -o $@ $^ $(CFLAGS)

build/hanoi_pile : obj/hanoi_pile.o obj/pile.o
	$(CC) -o $@ $^ $(CFLAGS)

obj/pile.o : head/pile.h
obj/hanoi.o : head/pile.h
obj/hanoi_pile.o : head/pile.h

obj/%.o : src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)
