# GetAways
## Timing

For example, a 4GHz processor performs 4,000,000,000 clock cycles per second.

Operations|Clock Cycles
-|-
shift between threads|20,000
int multiplication|10
int division|30
int addition, subtraction, bit-level|1

## int range

see chapter 2, figure 2.13.

![](./02.information/int.range.png)

## Assembly

```asm
%eip # indicates the address in memory for the next instruction
pushl   %ebp # push register ebp content to stack
```

## heap and stack

https://stackoverflow.com/questions/3707517/make-file-echo-displaying-path-string

```bash
$ ./stack_heap.o 
depth 10, stack at 0x7ff7b759a60b, heap at 0x7f92a87059e0
depth  9, stack at 0x7ff7b759a5eb, heap at 0x7f92a87059f0
depth  8, stack at 0x7ff7b759a5cb, heap at 0x7f92a8705a00
depth  7, stack at 0x7ff7b759a5ab, heap at 0x7f92a8705a10
depth  6, stack at 0x7ff7b759a58b, heap at 0x7f92a8705a20
depth  5, stack at 0x7ff7b759a56b, heap at 0x7f92a8705a30
depth  4, stack at 0x7ff7b759a54b, heap at 0x7f92a8705a40
depth  3, stack at 0x7ff7b759a52b, heap at 0x7f92a8705a50
depth  2, stack at 0x7ff7b759a50b, heap at 0x7f92a8705a60
depth  1, stack at 0x7ff7b759a4eb, heap at 0x7f92a8705a70
depth  0, stack at 0x7ff7b759a4cb, heap at 0x7f92a8705a80
$ ulimit -s
8192
```