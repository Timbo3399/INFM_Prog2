#include <stdio.h>

int iVarA = 73;
int iVarB = 42;
int iVarC = 7;

int main(void)
{
	//1.1
	printf("Wo im Speicher (Adressen in hexadezimal) sind diese Variablen abgelegt?\niVarA: %p\niVarB: %p\niVarB: %p\n",&iVarA, &iVarB, &iVarC);

	int* piVal = &iVarA;

	//1.2
	printf("Adresse von piVal: %p\n", &piVal);

	//1.3
	printf("Wert von piVal: %p\n", piVal);

	//1.4
	printf("Wert, auf den der Zeiger piVal zeigt: %d\n", *piVal);

	return 0;
}