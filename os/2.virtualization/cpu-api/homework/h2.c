#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int fd = open("./h2.output", O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
    int rc = fork();
    if (rc < 0)
    {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child
        if (write(fd, "child process write to file\n", 28) != 28)
        {
            write(STDERR_FILENO, "child process write file error", 36);
            return 1;
        }
        return 0;
    }
    else
    {
        // parent goes down this path (original process)
        if (write(fd, "parent process write to file\n", 29) != 29)
        {
            write(STDERR_FILENO, "parent process write file error", 36);
            return 1;
        }
    }
    return 0;
}
