#include <stdlib.h> // malloc
#include <stdio.h>  // printf

void check(int depth)
{
    char c;
    char *p = malloc(1);
    printf("depth %2d, stack at %p, heap at %p\n", depth, &c, p);
    if (depth <= 0)
        return;
    check(depth - 1);
}

int main()
{
    check(10);
    return 0;
}
