#include <stdio.h>

void DoCallbyReferenceArray1(int* pdA);
void DoCallbyReferenceArray2(int pdA[]);
void DoCallbyReferenceArray3(int pdA[]);

/*
 * Rufen Sie anschließend eine der drei Funktionen erneut auf und übergeben Sie statt aiArray jetzt NULL. Was passiert?
 * 
 * Exception thrown: write access violation. pdA was nullptr.
 * 
 * Ist damit das obige Problem gelöst?
 * 
 * Nein es ist nicht glößt sondern nur dem eigentlich Problem ausgewichen 
 */

int main(void)
{
	int aiArray[3] = { 0 };

	DoCallbyReferenceArray1(aiArray);
	DoCallbyReferenceArray2(aiArray);
	DoCallbyReferenceArray3(aiArray);

	printf("aiArray[0]:%i\naiArray[1]:%i\naiArray[2]:%i\n", aiArray[0], aiArray[1], aiArray[2]);

	DoCallbyReferenceArray3(NULL);

	return 0;
}

void DoCallbyReferenceArray1(int* pdA)
{
	if (pdA != NULL)
	{
		*pdA = 1; // First element
	}
}
void DoCallbyReferenceArray2(int pdA[])
{
	if (pdA != NULL)
	{
		pdA[1] = 2; // Second element
	}
}
void DoCallbyReferenceArray3(int pdA[])
{
	if (pdA != NULL)
	{
		pdA[2] = 3; // Third element
	}
}