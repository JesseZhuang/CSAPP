#include <stdio.h>
#include <limits.h>

int tadd_ok(int x, int y)
{
    int sum = x + y;
    printf("x=%d, y=%d, sum=%d\n", x, y, sum);
    int neg = x < 0 && y < 0 && sum >= 0;
    if (neg)
    {
        printf("negative overflow, sum - x = %d \n", (sum - x));
    }
    int pos = x >= 0 && y >= 0 && sum < 0;
    if (pos)
    {
        printf("positive overflow, sum - x = %d \n", (sum - x));
    }
    return !neg && !pos;
}

int main()
{
    printf("tadd_ok ? = %d\n", tadd_ok(INT_MAX, 1));
    printf("tadd_ok ? = %d\n", tadd_ok(-1, INT_MIN));
    printf("tadd_ok ? = %d\n", tadd_ok(INT_MIN, INT_MIN));
    return 0;
}
