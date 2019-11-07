# Process

One of the most fundamental abstractions of OS is process. The definition of a process, informally, is quite simple: it is a running program. A typical system may be seemingly running tens or even hundreds of processes at the same time and provides the illusion of a nearly-endless supply of said CPUs.

To implement virtualization of the CPU, and to implement it well, the OS will need both some low-level machinery as well as some high-level intelligence. We call the low-level machinery mechanisms; mechanisms are low-level methods or protocols that implement a needed piece of functionality. For example, we’ll learn later how to implement a context switch, which gives the OS the ability to stop running one program and start running another on a given CPU; this time-sharing mechanism is employed by all modern OSes.

On top of these mechanisms resides some of the intelligence in the OS, in the form of policies. Policies are algorithms for making some kind of decision within the OS. For example, given a number of possible programs to run on a CPU, which program should the OS run? A scheduling policy in the OS will make this decision, likely using historical information (e.g., which program has run more over the last minute?), workload knowledge (e.g., what types of programs are run), and performance metrics (e.g., is the system optimizing for interactive performance, or throughput?) to make its decision.

## The Abstraction-Process

The process’s machine state
- the memory that the process can address (called its address space)
- registers
-  program counter (PC) (sometimes called the instruction pointer or IP) tells us which instruction is currently being executed, a stack pointer and associated frame pointer are used to manage the stack for function parameters, local variables, and return addresses.
- Persistent storage devices. Such I/O information might include a list of the files the process currently has open.

## Process API
