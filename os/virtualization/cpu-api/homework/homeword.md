## Homework

1. Write a program that calls fork().Before calling fork(),have the main process access a variable (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? What happens to the variable when both the child and parent change the value of x?

```shell
$ h1.o
main (pid:68980)
hello, I am parent of 68985 (pid:68980)
global:5
local:6
hello, I am child (pid:68985)
global:3
local:4
$ h1w.o
main (pid:69780)
hello, I am child (pid:69781)
global:3
local:4
hello, I am parent of 69781 (wc:69781) (pid:69780)
global:5
local:6
```

2. Write a program that opens a file (with the open() system call) and then calls fork() to create a new process. Can both the child and parent access the file descriptor returned by open()? What happens when they are writing to the file concurrently, i.e., at the same time?

```shell
```

3. Write another program using fork(). The child process should print “hello”; the parent process should print “goodbye”. You should try to ensure that the child process always prints first; can you do this without calling wait() in the parent?
4. Write a program that calls fork() and then calls some form of exec() to run the program /bin/ls. See if you can try all of the variants of exec(), including execl(), execle(), execlp(), execv(), execvp(), and execvP(). Why do you think there are so many variants of the same basic call?
5. Now write a program that uses wait()to wait for the child process to finish in the parent. What does wait() return? What happens if you use wait() in the child?
6. Write a slight modification of the previous program, this time using waitpid() instead of wait(). When would waitpid() be useful?
7. Write a program that creates a child process, and then in the child closes standard output (STDOUT FILENO). What happens if the child calls printf() to print some output after closing the descriptor?
8. Write a program that creates two children, and connects the standard output of one to the standard input of the other, using the pipe() system call.