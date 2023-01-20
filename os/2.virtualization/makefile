SRCS := $(wildcard *.c) # all files with the .c extension will be stored in a variable SRCS
BINS := $(SRCS:%.c=%.o) # substitution reference, foo.c => foo.o

all: ${BINS}

%.o: %.c
	gcc -o $@ $< -Wall
