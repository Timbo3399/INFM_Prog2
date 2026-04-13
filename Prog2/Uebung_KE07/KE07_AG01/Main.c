#include <stdio.h>
#define ARRAY_LEN 10

unsigned int auiArray[ARRAY_LEN] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U };

int main(void)
{
	unsigned int* puiA;

	unsigned int* puiB;

	//Zuweisung mit NULL

	puiA = NULL;
	puiB = NULL;
	printf("Zuweisung mit NULL:\n");
	printf("   puiA = %p\n", (void*)puiA);
	printf("   puiB = %p\n\n", (void*)puiB);

	//Zuweisung einer Adresse (Verwenden Sie hierzu Arrayelemente)

	puiA = &auiArray[1];
	puiB = &auiArray[2];
	printf("Zuweisung einer Adresse:\n");
	printf("   puiA = %p\n", (void*)puiA);
	printf("   puiB = %p\n\n", (void*)puiB);

	//Inkrementieren und Dekrementieren (mit anschließendem printf()) 

	puiA = &auiArray[1];
	puiB = &auiArray[2];
	puiA++;
	puiB--;
	printf("Inkrementieren und Dekrementieren:\n");
	printf("   puiA++ = %p\n", (void*)puiA);
	printf("   puiB-- = %p\n\n", (void*)puiB);

	//Subtrahieren und Addieren (mit anschließendem printf())

	puiA = &auiArray[1];
	puiB = &auiArray[2];
	puiA = puiA+6;
	puiB = puiB-5;
	printf("Subtrahieren und Addieren:\n");
	printf("   puiA + 6 = %p\n", (void*)puiA);
	printf("   puiB - 5 = %p\n\n", (void*)puiB);

	//Differenz zweier Zeiger (Ausgabe mit printf())

	printf("Differenz zweier Zeiger:\n");
	printf("   puiA - puiB = %td\n\n", puiA - puiB);

	//Vergleichsoperatoren

	printf("Vergleichsoperatoren:\n");
	printf("   puiA == puiB  : %s\n", (puiA == puiB) ? "wahr" : "falsch");


	return 0;
}