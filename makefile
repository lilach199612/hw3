CC=gcc
FLAGS= -Wall -g
OBJECTS_MAIN_ISORT= isort.o
OBJECTS_MAIN_TXTFIND=txtfind.o

all: isort txtfind

isort: isort.c
	$(CC) $(FLAGS) isort.c -o isort

txtfind: txtfind.c 
	$(CC) $(FLAGS) txtfind.c -o txtfind


.PHONY: clean all

clean:
	rm -f isort txtfind


