#include <stdio.h>

int sum_elements(float a[], unsigned length)
{
    int i;
    float result = 0;
    // change to i < length to fix the bug
    // i, 1 promoted to unsigned
    for (i = 0; i <= length - 1; i++)
    {
        result += a[i];
    }
    return result;
}

int main()
{
    int i = 0;
    unsigned len = 0U;
    printf("unsigned 0u-1 %u\n", len - 1); //4294967295
    float a[] = {};
    sum_elements(a, 0u); // Segmentation fault : 11
    return 0;
}
