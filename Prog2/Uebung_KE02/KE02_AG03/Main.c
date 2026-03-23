#include <stdio.h>

void main()
{
	char cVar;
	int iVar;
	unsigned int uiVar;
	float fVar;
	double dVar;

	printf("Bitte geben Sie ein Zeichen (char) ein: ");
	scanf(" %c", &cVar);  // Leerzeichen wichtig (überspringt Whitespace) sonst wird enter als char gelesen

	printf("Bitte geben Sie eine ganze Zahl (int) ein: ");
	scanf("%d", &iVar);

	printf("Bitte geben Sie eine positive ganze Zahl (unsigned int) ein: ");
	scanf("%u", &uiVar);

	printf("Bitte geben Sie eine Kommazahl (float) ein: ");
	scanf("%f", &fVar);

	printf("Bitte geben Sie eine Kommazahl (double) ein: ");
	scanf("%lf", &dVar); //bei double muss immer lf sein



	printf("char: %c\n", cVar);
	printf("int: %d\n", iVar);
	printf("unsigned int: %u\n", uiVar);
	printf("float: %.2f\n", fVar);
	printf("double: %.2lf\n", dVar);

	/*
	Wird in diesem Fall gerundet? (Geben Sie 4.999 ein!)
	Ja es wird gerundet, da die Ausgabe auf 2 Nachkommastellen formatiert ist. In diesem Fall würde 4.999 auf 5.00 gerundet werden.
	*/

	char acStr[100];
	printf("Bitte gebe eine Zeichenkette ein: ");
	scanf("%s", &acStr);

	printf("Die eingegebene Zeichenkette ist: %s\n", acStr);
	/*So gibt es nicht alles aus nur bis zu ersten Leerzeichen*/
}