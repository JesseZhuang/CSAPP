#include <stdio.h>
#include <limits.h>

int uadd_ok(unsigned x, unsigned y)
{
    return x + y >= x;// overflow: sum < x
}

int main()
{
    printf("ok ? = %d\n", uadd_ok(1U, UINT_MAX));
    printf("ok ? = %d\n", uadd_ok(1U, 3U));
}
