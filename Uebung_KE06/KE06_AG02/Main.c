#include <stdio.h>

struct Address
{
	unsigned int uiZipCode;
};
typedef struct Address sAddress_t;
typedef sAddress_t* psAddress_t;

void vPrintAddress(sAddress_t sA);

int main(void)
{

	sAddress_t sAddress = { 0 };

	psAddress_t psAddress = &sAddress;

	//3.1 Geben Sie die sAddress auf der Konsole aus
	vPrintAddress(sAddress);

	//3.2
	sAddress.uiZipCode = 4711U;
	vPrintAddress(sAddress);

	//3.3
	psAddress->uiZipCode = 815U;
	vPrintAddress(sAddress);

	return 0;
}

void vPrintAddress(sAddress_t sA)
{
	printf("%u\n", sA.uiZipCode);
}