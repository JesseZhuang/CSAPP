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

## 3.2 Program Encodings
