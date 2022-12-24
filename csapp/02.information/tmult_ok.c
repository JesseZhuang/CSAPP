#include <limits.h>
#include <stdio.h>

int tmult_ok(int x, int y)
{
    int p = x * y;
    return !x || p / x == y;
}

// 1, handles case x = 0
// 2, x*y = product + t*2^w
// 3, product = x*q + r, |r| < |x|
// 4, q == y iff r == t == 0

// practice problem 2.36
int tmult_ok2(int x, int y)
{
    // tydef long long int64_t
    int64_t p = (int64_t)x * y;
    printf("unsigned p: %lld\n", p);
    printf("(int) p: %d\n", (int)p);
    printf("(unsigned int) p: %d\n", (unsigned int)p);
    return p == (int)p;
}

int main()
{
    printf("mutiply %d * %d\n", 2, INT_MAX);
    printf("no overflow ? %d\n", tmult_ok2(2, INT_MAX));
    printf("mutiply %d * %d\n", 2, 10);
    printf("no overflow ? %d\n", tmult_ok2(2, 10));
}
