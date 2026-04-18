#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

void fA(void);
int fB(void);
int* fC(unsigned int uiNumber);

int main(void)
{
	void (*pfA)(void) = fA;
	int (*pfB)(void) = fB;
	int* (*pfC)(unsigned int uiNumber) = fC;



	pfA();
	printf("%i\n", pfB());
	printf("%i\n", *pfC(1));

	_CrtDumpMemoryLeaks();
	return 0;
}

void fA(void)
{
	printf("Ing.-Inf. is at an Advanced Level\n");
}

int fB(void)
{
	static int iVal1 = 42;
	return (++iVal1);
}

int* fC(unsigned int uiNumber)
{
	static int iVal2;
	int* piRet = NULL;
	piRet = (int*)malloc(uiNumber * sizeof(int));
	if (piRet != NULL)
	{
		*piRet = 73 + (iVal2++);
	}
	return piRet;
}