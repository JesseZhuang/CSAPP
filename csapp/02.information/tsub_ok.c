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

int tsub_ok(int x, int y)
{
    return tadd_ok(x, -y); // problem when y is INT_MIN
}

int main()
{
    printf("INT_MIN: %d, -INT_MIN: %d\n", INT_MIN, -INT_MIN);
    printf("tsub_ok ? = %d\n", tsub_ok(1, INT_MIN));  // result ok, actually overflow 1+2147483648
    printf("tsub_ok ? = %d\n", tsub_ok(-1, INT_MIN)); // result overflow, actually ok -1+2147483648
    printf("tsub_ok ? = %d\n", tsub_ok(2, INT_MIN + 1)); // result overflow, actually overflow
    return 0;
}
