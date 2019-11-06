# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean # defines phony targets all and clean.

CC = gcc                        # compiler to use

LINKERFLAG = -lm

SRCS := $(wildcard *.c) # all files with the .c extension will be stored in a variable SRCS
BINS := $(SRCS:%.c=%) # substitution reference, foo.c => foo

all: ${BINS}

# This rule will be called for every value in ${BINS}
%: %.o # foo: foo.o
        @echo "Checking.."
		# $< is patterned to match prerequisites and $@ matches the target
        ${CC} ${LINKERFLAG} $< -o $@ # gcc -lm foo.o -o foo

%.o: %.c
        @echo "Creating object.."
        ${CC} -c $< # gcc -c foo.c

clean:
        @echo "Cleaning up..."
        rm -rvf *.o ${BINS}