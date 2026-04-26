#include <stdio.h>

#define SWAP(iX, iY) do { int __tmp = (iX); (iX) = (iY); (iY) = __tmp; } while(0)

#define ISODD(iX) (((iX) & 1) ? 1 : 0)

#define GETSECONDBYTE(uVal) ( (unsigned int)(((uVal) >> 8) & 0xFFu) )

int main(void)
{
    int iA = 1, iB = 2;
   printf("SWAP Test 1: a=%d, b=%d\n", iA, iB);
    SWAP(iA, iB);
   printf("After SWAP: a=%d, b=%d\n\n", iA, iB);

    int iX = 100, iY = -50;
    printf("SWAP Test 2: x=%d, y=%d\n", iX, iY);
    SWAP(iX, iY);
    printf("After SWAP: x=%d, y=%d\n\n", iX, iY);

    int iP = 7, iQ = 42;
    printf("SWAP Test 3: p=%d, q=%d\n", iP, iQ);
    SWAP(iP, iQ);
    printf("After SWAP: p=%d, q=%d\n\n", iP, iQ);

    int iN1 = 4, iN2 = 5, iN3 = -3;
    printf("ISODD(%d) = %d\n", iN1, ISODD(iN1));
    printf("ISODD(%d) = %d\n", iN2, ISODD(iN2));
    printf("ISODD(%d) = %d\n\n", iN3, ISODD(iN3));

    unsigned int uiV1 = 0x12345678u; //second byte = 0x56
    unsigned int uiV2 = 0x0000FF00u; //second byte = 0xFF
    unsigned int uiV3 = 0x00000000u; //second byte = 0x00

    printf("GETSECONDBYTE(0x%08X) = 0x%02X\n", uiV1, GETSECONDBYTE(uiV1));
    printf("GETSECONDBYTE(0x%08X) = 0x%02X\n", uiV2, GETSECONDBYTE(uiV2));
    printf("GETSECONDBYTE(0x%08X) = 0x%02X\n", uiV3, GETSECONDBYTE(uiV3));

    return 0;
}
