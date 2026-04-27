#include <stdio.h>

struct Rectangle {
	float fHeight;float fWidth;
};
typedef struct Rectangle sRect_t;
typedef sRect_t* psRect_t;


typedef struct Address sAddress_t;
typedef sAddress_t* psAddress_t;

void DoCallByValueStruct(sRect_t sR);
void DoCallByReferenceStruct(psRect_t psR);


void DoCallByValue(int iA);
void DoCallByReference(int* piA);


int main(void)
{
	int iTest = 42;
	DoCallByValue(iTest);
	printf("iTest: %d\n", iTest);
	DoCallByReference(&iTest);
	printf("iTest: %d\n", iTest);


	sRect_t sRect = { 1.F, 1.F };
	DoCallByValueStruct(sRect);
	printf("sRect.fHeight: %f\n", sRect.fHeight);
	DoCallByReferenceStruct(&sRect);
	printf("sRect.fHeight: %f\n", sRect.fHeight);
	return 0;
}

void DoCallByValue(int iA)
{
	iA = 73;
}

void DoCallByReference(int* piA) {
	*piA = 73;
}

void DoCallByValueStruct(sRect_t sR)
{
	sR.fHeight = 2.178F;
}

void DoCallByReferenceStruct(psRect_t psR) {
	psR->fHeight = 2.178F;
}