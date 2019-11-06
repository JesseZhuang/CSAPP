## Virtualizing cpu

```shell
# note, can use make file
$make
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

Each process accesses its own private virtual address space (sometimes just called its address space), which the OS somehow maps onto the physical memory of the machine. A memory reference within one running program does not affect the address space of other processes (or the OS itself); as far as the running program is concerned, it has physical memory all to itself. The reality, however, is that physical memory is a shared resource, managed by the operating system.

One issue with mem.c is that address space randomization is usually on by
default. To turn it off:

### macOS
From [stackoverflow](http://stackoverflow.com/questions/23897963/documented-way-to-disable-aslr-on-os-x)

Just compile/link as follows:
    gcc -o mem mem.c -Wall -Wl,-no_pie

### Linux

From Giovanni Lagorio:

Under Linux you can disable ASLR, without using a debugger, in (at least)  two ways:
* Use the command setarch to run a process with ASLR disabled; I typically run
  bash, with which I can execute examples, like this:
  `setarch $(uname --machine) --addr-no-randomize /bin/bash`
* Writing 0 into `/proc/sys/kernel/randomize_va_space`; you need to be
  root to do this and this change has (a non-permament) effect on the
  whole system, which is something you probably don't want. I use this
  one only inside VMs.

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

## Design Goals

Layers of abstraction: C -> assembly -> processors -> logic gates -> transistors.

Goals:
- performance, minimize overheads, space time trade off.
- protection, isolation, security.
- reliability, run non-stop.
- energy efficiency, mobility.

## History

Evolution path: libraries -> protection -> multiprogramming (Unix) -> Modern era: PC (DOS, Mac OS, Windows)

The idea of a system call was invented, pioneered by the Atlas computing system. Instead of providing OS routines as a library (where you just make a procedure call to access them), the idea here was to add a special pair of hardware instructions and hardware state to make the transition into the OS a more formal, controlled process.

The key difference between a system call and a procedure call is that a system call transfers control (i.e., jumps) into the OS while simultaneously raising the hardware privilege level. User applications run in what is referred to as user mode which means the hardware restricts what applications can do; for example, an application running in user mode can’t typically initiate an I/O request to the disk, access any physical memory page, or send a packet on the network. When a system call is initiated (usually through a special hardware instruction called a trap), the hardware transfers control to a pre-specified trap handler (that the OS set up previously) and simultaneously raises the privilege level to kernel mode. In kernel mode, the OS has full access to the hardware of the system and thus can do things like initiate an I/O request or make more memory available to a program. When the OS is done servicing the request, it passes control back to the user via a special return-from-trap instruction, which reverts to user mode while simultaneously passing control back to where the application left off.