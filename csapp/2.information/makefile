all: show-bytes bits

clean:
	@echo "deleting executables"
	@rm -f show-bytes.o bits.o

show-bytes: show-bytes.c
	gcc -o show-bytes.o show-bytes.c
bits: bits.c
	gcc -o bits.o bits.c
