CC=gcc
AR=ar
FLAGS= -Wall -g

all:libtxtfind.a txtfind.o isort.o
	$(CC) $(FLAGS) -o all txtfind.o ./libtxtfind.a
libtxtfind.a : txtfind.o isort.o
	$(CC) -shared -o libtxtfind.a txtfind.o isort.o
txtfind.o : txtfind.c txtfind.h
	$(CC) $(FLAGS) -fPIC -c txtfind.c
isort.o : isort.c isort.h
	$(CC) $(FLAGS) -c isort.c

.PHONY: clean all

clean: 
		rm -f *.o *.a all
