## Virtualizing cpu

```shell
$gcc -o cpu.o cpu.c -Wall
$./cpu.o A &  ./cpu.o B &  ./cpu.o C
$kill <progress_id> # to kill the above processes sent to background
$kill 44105
$ps -eaf | grep cpu.o
```

`./cpu.o A & ; ./cpu.o B & ; ./cpu.o C` does not work on mac: `-bash: syntax error near unexpected token `;'`.

## Virtualizing memory

```shell
$gcc -o mem.o mem.c -Wall
pid: (66455); value of p: 0; addr: 0x7fb5aac006a0
pid: (66455); value of p: 1; addr: 0x7fb5aac006a0
$ mem.o 1 &  mem.o 10 &
[1] 67113
[2] 67114
$ pid: (67114); addr pointed to by p: 0x7fab9b4006a0
pid: (67113); addr pointed to by p: 0x7fafd25026a0
pid: (67114); value of p: 11; addr: 0x7fab9b4006a0
pid: (67113); value of p: 2; addr: 0x7fafd25026a0
pid: (67114); value of p: 12; addr: 0x7fab9b4006a0
pid: (67113); value of p: 3; addr: 0x7fafd25026a0
pid: (67114); value of p: 13; addr: 0x7fab9b4006a0
pid: (67113); value of p: 4; addr: 0x7fafd25026a0
```

Each process accesses its own private virtual address space (sometimes just called its address space), which the OS somehow maps onto the physical memory of the machine. For this example to work, you need to make sure address-space randomization is disabled. A memory reference within one running program does not affect the address space of other processes (or the OS itself); as far as the running program is concerned, it has physical memory all to itself. The reality, however, is that physical memory is a shared resource, managed by the operating system.

## Concurrency

```shell
$gcc -o threads.o threads.c -Wall [-pthread]
$threads.o 10000
Initial value : 0
Final value   : 20000
$ threads.o 100000
Initial value : 0
Final value   : 149839
```

## Persistence

```shell
$gcc -o io.o io.c -Wall
$io.o
$less tempFile
```

These system calls (`open()`, `write()`, `close()`) are routed to the part of the operating sys- tem called the file system, which then handles the requests and returns some kind of error code to the user.

For performance reasons, most file systems first delay such writes for a while, hoping to batch them into larger groups. To handle the problems of sys- tem crashes during writes, most file systems incorporate some kind of intricate write protocol, such as journaling or copy-on-write, carefully ordering writes to disk to ensure that if a failure occurs during the write sequence, the system can recover to reasonable state afterwards. To make different common operations efficient, file systems employ many differ- ent data structures and access methods, from simple lists to complex b- trees.