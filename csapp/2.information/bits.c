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
/* Return 1 when x ==y 0 otherwise with bit operation. */
int bool_and(int x, int y)
{
    return !(x^y);
}

void show_bytes(unsigned char *start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
        // %.2x hex at least two digits
        printf(" %.2x", start[i]); //line:data:show_bytes_printf
    printf("\n");
}

void show_int(int x)
{
    show_bytes((unsigned char *)&x, sizeof(int));
}

void shiftGreaterThanWordSize()
{
    // bits.c:68:28: warning: shift count >= width of type [-Wshift-count-overflow]
    int val = 0xFEDCBA98;
    int lval = (val  << 32);
    int aval = (val  >> 36);
    unsigned uval = (val >> 40);
    int status = system("./show-bytes.o 0xFEDCBA98");
    printf("system call return code %d\n", status);
    printf("0xFEDCBA98 << 32 == ");
    show_int(lval);
    printf("0xFEDCBA98 >> 36 == ");
    show_int(aval);
    printf("0xFEDCBA98u >> 40 == ");
    show_int(uval);
    // on mac, without parenthesis
    // 0xFEDCBA98 << 32 ==  05 00 00 00
    // 0xFEDCBA98 >> 36 ==  05 00 00 00
    // 0xFEDCBA98u >> 40 ==  05 00 00 00
    // on mac with parenthesis
    // 0xFEDCBA98 << 32 ==  98 ba dc fe
    // 0xFEDCBA98 >> 36 ==  a9 cb ed ff
    // 0xFEDCBA98u >> 40 ==  ba dc fe ff
}

int main()
{
    int x[5];
    int i = 0;
    for (i = 0; i < 5; i++) x[i] = i + 1;
    reverse_array(x, 5);
    for (i = 0; i < 5; i++) printf("x[%d]=%d\n", i, x[i]);

    shiftGreaterThanWordSize();

    return 0;
}
