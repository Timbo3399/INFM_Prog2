#include <stdio.h>

#define SWAP(iX, iY) do { int __tmp = (iX); (iX) = (iY); (iY) = __tmp; } while(0)

#define ISODD(iX) (((iX) & 1) ? 1 : 0)

#define GETSECONDBYTE(uVal) ( (unsigned int)(((uVal) >> 8) & 0xFFu) )

int main(void)
{
    int a = 1, b = 2;
    printf("SWAP Test 1: a=%d, b=%d\n", a, b);
    SWAP(a, b);
    printf("After SWAP: a=%d, b=%d\n\n", a, b);

    int x = 100, y = -50;
    printf("SWAP Test 2: x=%d, y=%d\n", x, y);
    SWAP(x, y);
    printf("After SWAP: x=%d, y=%d\n\n", x, y);

    int p = 7, q = 42;
    printf("SWAP Test 3: p=%d, q=%d\n", p, q);
    SWAP(p, q);
    printf("After SWAP: p=%d, q=%d\n\n", p, q);

    int n1 = 4, n2 = 5, n3 = -3;
    printf("ISODD(%d) = %d\n", n1, ISODD(n1));
    printf("ISODD(%d) = %d\n", n2, ISODD(n2));
    printf("ISODD(%d) = %d\n\n", n3, ISODD(n3));

    unsigned int v1 = 0x12345678u; //second byte = 0x56
    unsigned int v2 = 0x0000FF00u; //second byte = 0xFF
    unsigned int v3 = 0x00000000u; //second byte = 0x00

    printf("GETSECONDBYTE(0x%08X) = 0x%02X\n", v1, GETSECONDBYTE(v1));
    printf("GETSECONDBYTE(0x%08X) = 0x%02X\n", v2, GETSECONDBYTE(v2));
    printf("GETSECONDBYTE(0x%08X) = 0x%02X\n", v3, GETSECONDBYTE(v3));

    return 0;
}
