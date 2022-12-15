#include <stdio.h>
#include <string.h>

/* Prototype for library function strlen */
// size_t strlen(const char *s);
// typedef unsigned int size_t;

int isLonger(char *s, char *t)
{
    unsigned int diff = strlen(s) - strlen(t);
    printf("minus result: %u\n", diff);
    return diff > 0;
    // return strlen(s) > strlen(t);
    // comapre instead of arithmetic
}

int main()
{
    char *s = "abc";
    char *t = "abcdef";
    // diff is 4294967293
    printf("%s longer than %s : %d\n", s, t, isLonger(s, t));
    printf("%s longer than %s : %d\n", t, s, isLonger(t, s));
    return 0;
}
