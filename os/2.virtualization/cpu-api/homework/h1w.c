#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global = 1;

int main(int argc, char *argv[])
{
    int local = 2;
    printf("main (pid:%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0)
    {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int)getpid());
        global = 3;
        local = 4;
        printf("global:%d\n", global);
        printf("local:%d\n", local);
    }
    else
    {
        int wc = wait(NULL);
        // parent goes down this path (original process)
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
               rc, wc, (int)getpid());
        global = 5;
        local = 6;
        printf("global:%d\n", global);
        printf("local:%d\n", local);
    }
    return 0;
}
