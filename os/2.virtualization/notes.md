# 4 Processes

One of the most fundamental abstractions of OS is process. The definition of a process, informally, is quite simple: it is a running program. A typical system may be seemingly running tens or even hundreds of processes at the same time and provides the illusion of a nearly-endless supply of said CPUs.

To implement virtualization of the CPU, and to implement it well, the OS will need both some low-level machinery as well as some high-level intelligence. We call the low-level machinery mechanisms; mechanisms are low-level methods or protocols that implement a needed piece of functionality. For example, we’ll learn later how to implement a context switch, which gives the OS the ability to stop running one program and start running another on a given CPU; this time-sharing mechanism is employed by all modern OSes.

On top of these mechanisms resides some of the intelligence in the OS, in the form of policies. Policies are algorithms for making some kind of decision within the OS. For example, given a number of possible programs to run on a CPU, which program should the OS run? A scheduling policy in the OS will make this decision, likely using historical information (e.g., which program has run more over the last minute?), workload knowledge (e.g., what types of programs are run), and performance metrics (e.g., is the system optimizing for interactive performance, or throughput?) to make its decision.

## 4.1 The Abstraction-Process

The process’s machine state
- the memory that the process can address (called its address space)
- registers
-  program counter (PC) (sometimes called the instruction pointer or IP) tells us which instruction is currently being executed, a stack pointer and associated frame pointer are used to manage the stack for function parameters, local variables, and return addresses.
- Persistent storage devices. Such I/O information might include a list of the files the process currently has open.

## 4.2 Process API

- Create: any command
- Destroy: `kill`
- Wait: listener on a process to wait for stop signal
- Miscellaneous control: suspend, resume
- Status: how long, state

## 4.3 Process Creation

![](./4.1.loading.program.png)

1. Load code and any static data into memory from executable on disk. Modern OS does this lazily. Ealier OS eagerly.
1. Allocate stack. C programs use the stack for local variables, function parameters, and return addresses. The OS will also likely initialize the stack with arguments; specifically, it will fill in the parameters to the main() function, i.e., argc and the argv array.
1. Allocate heap. In C programs, the heap is used for explicitly requested dynamically-allocated data; programs request such space by calling `malloc()` and free it explicitly by calling `free()`. The heap is needed for data structures such as linked lists, hash tables, trees, and other interesting data structures.
1. Initialization tasks including IO. For example, in UNIX systems, each process by default has three open file descriptors, for standard input, output, and error.
1. Start the program running at the entry point, namely `main()`. OS transfers control of the CPU to the newly-created process, and thus the program begins its execution.

## 4.4 Process States

1. Running: executing.
1. Ready: A process is ready to run but for some reason the OS has chosen not to run it at this given moment.
1. Blocked: A process has performed some kind of operation that makes it not ready to run until some other event takes place.

![process state transitions](process.state.transitions.png)

Once a process has become blocked (e.g., by initiating an I/O operation), the OS will keep it as such until some event occurs (e.g., I/O completion); at that point, the process moves to the ready state again (and potentially immediately to running again, if the OS so decides).

![](process.state.trace.png)

## 4.5 Data Structures

```C
// the registers xv6 will save and restore to stop and subsequently restart a process
struct context {
  int eip;
  int esp;
  int ebx;
  int ecx;
  int edx;
  int esi;
  int edi;
  int ebp;
};

// the different states a process can be in
enum proc_state {
    UNUSED, EMBRYO, SLEEPING,
    RUNNABLE, RUNNING, ZOMBIE
};

// the information xv6 tracks about each process including its register context and state
struct proc {
    char *mem; // Start of process memory
    uint sz; // Size of process memory
    char *kstack; // Bottom of kernel stack
    enum proc_state state;
    int pid; // Process ID
    struct proc *parent; // Parent process
    void *chan; // If non-zero, sleeping on chan
    int killed; // If non-zero, have been killed
    struct file *ofile[NOFILE]; // Open files
    struct inode *cwd; // Current directory
    struct context context; // Switch here to run process
    struct trapframe *tf; // Trap frame for the current interrupt
};
```

This final (`ZOMBIE`) state can be useful as it allows other processes (usually the parent that created the process) to examine the return code of the process and see if the just-finished process executed successfully (usually, programs return zero in UNIX-based systems when they have accomplished a task successfully, and non-zero otherwise). When finished, the parent will make one final call (e.g., wait()) to wait for the completion of the child, and to also indicate to the OS that it can clean up any relevant data structures that referred to the now-extinct process.

Sometimes people refer to the individual structure that stores information about a process as a Process Control Block (PCB), a fancy way of talking about a C structure that contains information about each process (process list).

# 5 CPU API

## 5.1 The `fork()` System Call

```shell
$p1.o
hello world (pid:79615)
hello, I am parent of 79627 (pid:79615)
hello, I am child (pid:79627)
$
```

The odd part: the process that is created is an **almost** exact copy of the calling process. That means that to the OS, it now looks like there are two copies of the program p1 running, and both are about to return from the `fork()` system call. The newly-created process (called the child, in contrast to the creating parent) doesn’t start running at `main()`, like you might expect (note, the “hello, world” message only got printed out once); rather, it just comes into life as if it had called `fork()` itself. You might have noticed: the child isn’t an exact copy. Specifically, although it now has its own copy of the address space (i.e., its own private memory), its own registers, its own PC, and so forth, the value it returns to the caller of fork() is different. Specifically, while the parent receives the PID of the newly-created child, the child receives a return code of zero. This differentiation is useful, because it is simple then to write the code that handles the two different cases.

The order of execution for the parent and child processes is not deterministic and decided by the OS scheduler.

## 5.2 The `wait()` System Call

```shell
$ os/virtualization/cpu-api/p2.o
hello world (pid:31520)
hello, I am child (pid:31527)
hello, I am parent of 31527 (wc:31527) (pid:31520)
$
```

It can be very useful for the parent process can wait for the child with `wait()` or the more complete sibling `waitpid()`. The order is deterministic. If the parent does happen to run first, it will immediately call `wait()`; this system call won’t return until the child has run and exited.

## 5.3 The `exec()` System Call

```shell
$ os/virtualization/cpu-api/p3.o
hello world (pid:37598)
hello, I am child (pid:37599)
wc: p3.c: open: No such file or directory
hello, I am parent of 37599 (wc:37599) (pid:37598)
$
$ p3.o
hello world (pid:37841)
hello, I am child (pid:37842)
      36     120     990 p3.c
hello, I am parent of 37842 (wc:37842) (pid:37841)
```

```shell
$ p4.o
hostname:cpu-api zexiz$ ls
makefile  p1.c      p1.o      p2.c      p2.o      p3.c      p3.o      p4.c      p4.o      p4.output
$ cat p4.output
      38     118     942 p4.c
```

The `fork()` system call is strange; its partner in crime, `exec()`, is not so normal either. What it does: given the name of an executable (e.g., `wc`), and some arguments (e.g., p3.c), it loads code (and static data) from that executable and overwrites its current code segment (and current static data) with it; the heap and stack and other parts of the memory space of the program are re-initialized. Then the OS simply runs that program, passing in any arguments as the argv of that process. Thus, it does not create a new process; rather, it transforms the currently running program (formerly p3) into a different running program (`wc`). After the `exec()` in the child, it is almost as if p3.c never ran; a successful call to `exec()` never returns.

## 5.4 Motivating the API

The separation of `fork()` and `exec()` is essential in building a UNIX shell, because it lets the shell run code after the call to `fork()` but before the call to `exec()`; this code can alter the environment of the about-to-be-run program, and thus enables a variety of interesting features to be readily built.

In most cases, the shell then figures out where in the file system the executable resides, calls `fork()` to create a new child process to run the command, calls some variant of `exec()` to run the command, and then waits for the command to complete by calling `wait()`. When the child completes, the shell returns from `wait()` and prints out a prompt again, ready for your next command.

UNIX pipes are implemented in a similar way, but with the `pipe()` system call. In this case, the output of one process is connected to an in- kernel pipe (i.e., queue), and the input of another process is connected to that same pipe; thus, the output of one process seamlessly is used as input to the next, and long and useful chains of commands can be strung together.

The `kill()` system call is used to send signals to a process, including directives to go to sleep, die, and other useful imperatives. In fact, the entire signals subsystem provides a rich infrastructure to deliver external events to processes, including ways to receive and process those signals.

# 6 CPU Mechanism-Limited Direct Execution

The basic idea is simple: run one process for a little while, then run another one, and so forth. By time sharing the CPU in this manner, virtualization is achieved. Obtaining high performance (avoid overhead) while maintaining control is thus one of the central challenges in building an operating system.

## 6.1 Limited Direct Execution

![direct execution without limit](direct.execution.protocol.png)

1. How can the OS make sure the program doesn’t do anything that we don’t want it to do, while still running it efficiently?
1. How does the operating system stop it from running and switch to another process, thus implementing the time sharing we require to virtualize the CPU?

## 6.2 Problem 1: Restricted Operations

A process must be able to perform I/O and gaining access to more resources such as CPU and memory, but without giving the process complete control over the system. How can the OS and hardware work together to do so?

Thus, the approach we take is to introduce a new processor mode, known as **user mode**; code that runs in user mode is restricted in what it can do. For example, when running in user mode, a process can’t issue I/O requests; doing so would result in the processor raising an exception; the OS would then likely kill the process.

In contrast to user mode is **kernel mode**, which the operating system (or kernel) runs in. In this mode, code that runs can do what it likes, including privileged operations such as issuing I/O requests and executing all types of restricted instructions.

The hardware assists the OS by providing different modes of execution. In user mode, applications do not have full access to hardware resources. In kernel mode, the OS has access to the full resources of the machine. Special instructions to trap into the kernel and return-from-trap back to user-mode programs are also provided, as well as instructions that allow the OS to tell the hardware where the trap table resides in memory.

System calls allow the kernel to carefully expose certain key pieces of functionality to user programs, such as accessing the file system, creating and destroying processes, communicating with other processes, and allocating more memory. Most operating systems provide a few hundred calls (see the POSIX standard for details); early Unix systems exposed a more concise subset of around twenty calls.

A system call in C, such as `open()` or `read()`, looks just like a procedure call. It is a procedure call, but hidden in- side that procedure call is the famous *trap instruction*. The parts of the C library that make system calls are hand-coded in assembly, as they need to carefully follow convention in order to process arguments and return values (onto stack or specific registers agreed upon) correctly, as well as execute the hardware-specific trap instruction. And now you know why you personally don’t have to write assembly code to trap into an OS; somebody has already written that assembly for you.

The hardware needs to be a bit careful when executing a trap, in that it must make sure to save enough of the caller’s registers in order to be able to return correctly when the OS issues the return-from-trap instruction. On x86, for example, the processor will push the program counter, flags, and a few other registers onto a per-process kernel stack; the return-from- trap will pop these values off the stack and resume execution of the user- mode program (see the Intel systems manuals for details).

To specify the exact system call, a system-call number is assigned to each system call. The user code is responsible for placing the desired system-call number in a register or at a specified location on the stack; the OS, inside the trap handler, examines this number, ensures it is valid, and, executes the corresponding code. This level of indirection serves as a form of protection; user code cannot specify an exact address to jump to, but rather must request a particular service via number.

![](direct.execution.protocol.limited.png)

### 6.3 Problem 2 Switching Between Processes

If a process is running on the CPU, this by definition means the OS is not running and OS cannot do anything. How can the operating system regain control of the CPU?

**A Cooperative Approach: Wait For System Calls**

Thus, you might ask, how does a friendly process give up the CPU in this utopian world? Most processes, as it turns out, transfer control of the CPU to the OS quite frequently by making system calls.
- to open a file and subsequently read it
- to send a message to another machine
- to create a new process
- illegal op: divide by zero, illegal access memory

Systems like this often include an explicit `yield` system call, which does nothing except to transfer control to the OS so it can run other processes.

In a cooperative scheduling system, the OS regains control of the CPU by waiting for a system call or an illegal operation of some kind to take place. What happens, for example, if a process (whether malicious, or just full of bugs) ends up in an infinite loop, and never makes a system call?

**A Non-Cooperative Approach: The OS Takes Control**

Your only recourse when a process gets stuck in an infinite loop is to resort to the age-old solution to all problems in computer systems: reboot the machine.

A timer device can be programmed to raise an interrupt every so many milliseconds. The addition of a timer interrupt gives the OS the ability to run again on a CPU (through a pre-configured interrupt handler) even if processes act in a non-cooperative fashion. Thus, this hardware feature is essential in helping the OS maintain control of the machine.

At boot time, he OS must inform the hardware of which code to run when the timer interrupt occurs and start the timer, which is of course a privileged operation.

**Saving and Restoring Context**

When the OS regained control, the scheduler will make a decision: whether to continue running the currently-running process, or switch to a different one.

```shell
# void swtch(struct context **old, struct context *new);
# Save current register context in old
# and then load register context from new.
.globl swtch
swtch:
  # Save old registers
  movl 4(%esp), %eax # put old ptr into eax
  popl 0(%eax) # save the old IP
  movl %esp, 4(%eax) # and stack
  movl %ebx, 8(%eax) # and other registers
  movl %ecx, 12(%eax)
  movl %edx, 16(%eax)
  movl %esi, 20(%eax)
  movl %edi, 24(%eax)
  movl %ebp, 28(%eax)
  # Load new registers
  movl 4(%esp), %eax # put new ptr into eax
  movl 28(%eax), %ebp # restore other registers
  movl 24(%eax), %edi
  movl 20(%eax), %esi
  movl 16(%eax), %edx
  movl 12(%eax), %ecx
  movl 8(%eax), %ebx
  movl 4(%eax), %esp # stack is switched here
  pushl 0(%eax) # return addr put in place
  ret # finally return into new ctxt
```

Note that there are two types of register saves/restores that happen during this protocol. The first is when the timer interrupt occurs; in this case, the user registers of the running process are implicitly saved by the hardware, using the kernel stack of that process. The second is when the OS decides to switch from A to B; in this case, the kernel registers are explicitly saved by the software (i.e., the OS), but this time into memory in the process structure of the process. The latter action moves the system from running as if it just trapped into the kernel from A to as if it just trapped into the kernel from B.

How long does context switch or a system call take? There is a tool called `lmbench` [MS96] that measures exactly those things, as well as a few other performance measures that might be relevant. Results have improved quite a bit over time, roughly tracking processor performance. For example, in 1996 running Linux 1.3.37 on a 200-MHz P6 CPU, system calls took roughly 4 microseconds, and a context switch roughly 6 microseconds [MS96]. Modern systems perform almost an order of magnitude better, with sub-microsecond results on systems with 2- or 3-GHz processors. It should be noted that not all operating-system actions track CPU performance. As Ousterhout observed, many OS operations are memory intensive, and memory bandwidth has not improved as dramatically as processor speed over time [O90]. Thus, depending on your workload, buying the latest and greatest processor may not speed up your OS as much as you might hope.

### 6.4 Worried About Concurrency?

What if?

- when you’re handling one interrupt and another one happens
- during a system call, a timer interrupt occurs

The OS does indeed need to be concerned as to what happens if, during interrupt or trap handling, another interrupt occurs.

One simple thing an OS might do is disable interrupts during interrupt processing; doing so ensures that when one interrupt is being handled, no other one will be delivered to the CPU. Of course, the OS has to be careful in doing so; disabling interrupts for too long could lead to lost interrupts, which is (in technical terms) bad.

Operating systems also have developed a number of sophisticated locking schemes to protect concurrent access to internal data structures. This enables multiple activities to be on-going within the kernel at the same time, particularly useful on multiprocessors.

**Reboot is Useful**

Specifically, reboot is useful because it moves software back to a known and likely more tested state. Reboots also reclaim stale or leaked resources (e.g., memory) which may otherwise be hard to handle. Finally, reboots are easy to automate. For all of these reasons, it is not uncommon in large-scale cluster Internet services for system management software to periodically reboot sets of machines in order to reset them and thus obtain the advantages listed above.

# 7 Scheduling

Scheduling employs a series of policies (sometimes called disciplines). The origins of scheduling, in fact, predate computer systems; early approaches were taken from the field of operations management and applied to computers. This reality should be no surprise: assembly lines and many other human endeavors also require scheduling, and many of the same concerns exist therein, including a laser-like desire for efficiency.

## 7.1 Workload Assumptions

1. Each job runs for the same amount of time.
2. All jobs arrive at the same time.
3. Once started, each job runs to completion.
4. All jobs only use the CPU (i.e., they perform no I/O)
5. The run-time of each job is known.

Many of these assumptions were unrealistic and some assumptions are more unrealistic than others in this chapter. In particular, it might bother you that the run-time of each job is known: this would make the scheduler omniscient, which, although it would be great (probably), is not likely to happen anytime soon.

## 7.2 Scheduling Metrics

The turnaround time of a job is defined as the time at which the job completes minus the time at which the job arrived in the system, which is a performance metric.

$T_{turnaround} = T_{completion} - T_{arrival}$

Another metric of interest is fairness, as measured (for example) by Jain’s Fairness Index. Performance and fairness are often at odds in scheduling; a scheduler, for example, may optimize performance but at the cost of preventing a few jobs from running, thus decreasing fairness. This conundrum shows us that life isn’t always perfect.

## 7.3 First In, First Out

FIFO has a number of positive properties: it is clearly simple and thus easy to implement. And, given our assumptions, it works pretty well.

![](fifo.convoy.png)

Job A runs first for the full 100 seconds before B or C even get a chance to run. Thus, the average turnaround time for the system is high:a painful 110 seconds. This problem is generally referred to as the convoy effect, where a number of relatively-short potential consumers of a resource get queued behind a heavyweight resource consumer.

## 7.4 Shortest Job First (SJF)

Shortest Job First (SJF) represents a general scheduling principle that can be applied to any system where the perceived turnaround time per customer (or, in our case, a job) matters. For example, grocery stores commonly have a “ten-items-or-less” line to ensure that shoppers with only a few things to purchase don’t get stuck behind the family preparing for some upcoming nuclear winter.

Simply by running B and C before A, SJF reduces average turnaround from 110 seconds to 50, more than a factor of two improvement.

In the old days of batch computing, a number of non-preemptive schedulers were developed; such systems would run each job to completion before considering whether to run a new job. Virtually all modern schedulers are preemptive, and quite willing to stop one process from running in order to run another. This implies that the scheduler employs the mechanisms we learned about previously in particular, the scheduler can perform a context switch, stopping one running process temporarily and resuming (or starting) another.

## 7.5 Shortest Time-to-Completion First (STCF)

We need to relax assumption 3 (jobs must run to completion). SJF is a non-preemptive scheduler. Now the schedule can preempty job A when jobs B and C arrive 10 s later. Preemptive Shortest Job First (PSJF).

Result is average turnaround time of 50 s: ((120-0) + (20-10) + (30-10)) / 3 = 50.

## 7.6 A New Metric: Response Time

For a number of early batch computing systems, STCF policy made some sense. However, the introduction of time-sahred machines changed all that.

$T_{response} = T_{firstrun} - T_{arrival}$

With above schedule (A arriving at 0, B and C at 10), the resposne time of each job is 0 for A and B, and 10 for C (average 3.33).

While great for turnaround time, STCF is quite bad for response time and interactivity.

## 7.7 Round Robin

![](7.7.round.robin.png)

In figure 7.7 above, average response time of RR is (0+1+2)/3 = 1; for SJF (0+5+10)/3 = 5.

Round-Robin (RR) scheduling [K64]. RR runs a job for a time slice (i.e., scheduling quantum) and then switches to the next job in the run queue. Note the length of the time slice must be a multiple of the timer-interrupt period.

The length of the time slice is critical for RR. The shorter it is, the better the performance of RR for response-time metric. However, too short is problematic: the cost of context switching will dominate overall performance. System designer can make a right trade-off on the length of time slice, making it long enough to amortize the cost of context switching without making it so long that the system is no longer responsive. Tip: e.g., if the time slice is 10 ms, and the context-switch cost is 1 ms, about 10% is spent switching and wasted. If we increase time slice to 100 ms, less than 1% is spent switching.

Context switching doe not arise solely from OS actions of saving and restoring registers. Programs also build up a great deal of state in CPU caches, (Translation Lookaside Buffer) TLBs, branch predictors, and other on-chip hardware [MB91].

RR is a perfect scheduler if response time is our only metric. Average response time is 14s in figure 7.7. RR is nearly pessimal, even worse than simple FIFO in many cases in terms of turnaround time. More generally, any policy that is fair, i.e., evenly divides the CPU among active processes on a small time scale, will perform pooly on metrics such as turnaround time.

- SJF STCF optimizes turnaround time
- RR optimizes response time

## 7.8 Incorportating I/O


<!-- references -->

[K64]: “Analysis of a Time-Shared Processor”, Leonard Kleinrock, Naval Research Logistics Quarterly, 11:1, pages 59–73, March 1964. May be the first reference to the round-robin scheduling algorithm; certainly one of the first analyses of said approach to scheduling a time-shared system.
[MB91]: “The effect of context switches on cache performance”, Jeffrey C. Mogul and Anita Borg, ASPLOS, 1991, A nice study on how cache performance can be affected by context switching; less of an issue in today’s systems where processors issue billions of instructions per second but context-switches still happen in the millisecond time range.