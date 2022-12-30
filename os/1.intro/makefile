# A rule is in below format
# target: prerequisites
# <TAB> recipe

# first target is default target
all: cpu mem threads io

clean:
	@echo "deleting executables"
	@rm -f cpu.o mem.o threads.o io.o

cpu: cpu.c common.h
	gcc -o cpu.o cpu.c -Wall

mem: mem.c common.h
	gcc -o mem.o mem.c -Wall

# https://stackoverflow.com/questions/2127797/significance-of-pthread-flag-when-compiling
threads: threads.c common.h common_threads.h
	gcc -o threads.o threads.c -Wall -pthread

io: io.c common.h
	gcc -o io.o io.c -Wall
