#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// no third location, no performance gain, intellectural amusement
void inplace_swap(int *x, int *y)
{// assume *x == a, *y == b
    *y = *x ^ *y; // *y := a^b
    *x = *x ^ *y; // *x := b
    *y = *x ^ *y; // *y = a
}

void reverse_array(int a[], int cnt)
{
    int first, last;
    for (first = 0, last = cnt - 1; first < last; first++, last--)
    {
        inplace_swap(&a[first], &a[last]);
    }
}

// FAKE bit_clear
int bit_clear(int x, int m)
{
    int mask = ~m;
    return x & mask;
}
// fake bit_set
int bit_set(int x, int m)
{
    return x | m; // bit=1 in m should be set to 1 otherwise no change , so OR
}

/* Compute x|y using only calls to functions bit_set and bit_clear */
// example x 1010 y 1000 result 1010
int bool_or(int x, int y)
{
    return bit_set(x, y);
}
/* Compute x^y using only calls to functions bit_set and bit_clear */
// example: x 1010 y 1101 result 0111
int bool_xor(int x, int y)
{
    return bit_set(bit_clear(x, y), bit_clear(y, x));
}

int main()
{
    int x[5];
    int i = 0;
    for (i = 0; i < 5; i++) x[i] = i + 1;
    reverse_array(x, 5);
    for (i = 0; i < 5; i++) printf("x[%d]=%d\n", i, x[i]);
    return 0;
}
