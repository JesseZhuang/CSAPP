# Chapter 3 Machine-Level Representation of Programs

Assembly code is highly machine specific.

Relative to the computations expressed in the C code, optimizing compilers can

- rearrange execution order
- eliminate unneeded computations
- replace slow operations with faster ones
- even change recursive computations into iterative ones

The extension of IA32 to 64 bits, x86-64, was originally developed by Advanced Micro Devices (AMD).

- 32-bit machine can use around 4 Gb (2^32 bytes) random-access memory
- 64-bit machine can use up to 256 terabytes (2^48 bytes)

## 3.1 A Historical Perspective

![](./moores.law.png)

Core i7: (2008, 781 M transistors). Incorporated both hyperthreading and multi-core, with the initial version supporting two executing programs on each core and up to four cores on each chip.

Linux uses a memory model called flat addressing, where the entire memory space is viewed as a large array of bytes.

Over time, a number of formats and instructions have been added to x86 for manipulating vectors of small integers and floating-point numbers. They were added to improve performance on multimedia applications, such as image processing, audio and video encoding and decoding, and 3D graphics. GCC will make use of more recent extensions only when given specific command line options or when compiling for 64 bit operation.

## 3.2 Program Encodings

```bash
$gcc -O1 -o p p1.c p2.c
# note O1 not 01 level 1 optimization, in practice level 2 is better choice for performance
```

1. expand source code for `#include` and macros (`#define`)
1. gernerate assembly code versions p1.s and p2.s
1. the assembler converts the assembly code into binary object code p1.o and p2.o. object code is one form of machine code. It contains binary representations of all instructions, but the addresses of the global values are not filled in yet.
1. the linker merges object-code files along with library and generates the final executable file p. Executable code is the second form of machine code, the exact form executed by the processor.

### 3.2.1 Machine-Level Cdoe

Instruction set architecture (ISA): IA32 and x86-64.

1. ISA defines processor state, instruction format and effect on the state. Describe behavior as if instructions were executed in sequence. Processor hardware actually executes concurrently but employ safeguards to ensure behavior matches.
1. Memory addresses are virtual, providing a memory model appears to be a very large byte array.

Assembly code is close to machine code. Its main feature is a more readable textual format.

1. Program counter (PC) `%eip` in IA32 indicates the address in memory for the next instruction.
1. Integer register file contains 8 registers storing 32-bit values, which can hold pointers or integer data. Some registers are used to keep track of program state, others temporary data, such as local variables of a procedure, and function return value.
1. condition code registers for `if` and `while` statements
1. floating-point registers

Assembly code makes no distinctions between signed and unsigned integers, between different type of pointers, or even between pointers and integers.

A typical program will only have access to a few megabytes. The OS manages the virtual address space, translating virtual into actual processor memory.

### 3.2.2 Code Examples



### 3.2.3
