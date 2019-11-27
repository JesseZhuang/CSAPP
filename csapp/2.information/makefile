all: show-bytes bits sum_elements

clean:
	@echo "deleting executables"
	@rm -f show-bytes.o bits.o sum_elements.o

show-bytes: show-bytes.c
	gcc -o show-bytes.o show-bytes.c
bits: bits.c
	gcc -o bits.o bits.c
sum_elements: sum_elements.c
	gcc -o sum_elements.o sum_elements.c
