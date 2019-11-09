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
        printf("global:%d", global);
        printf("global:%d", local);
    }
    else
    {
        // parent goes down this path (original process)
        printf("hello, I am parent of %d (pid:%d)\n",
               rc, (int)getpid());
        printf("global:%d", global);
        printf("global:%d", local);
    }
    return 0;
}
