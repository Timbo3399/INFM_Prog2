#include <stdio.h>

void main()
{
	char cVal = 'x';
	short int siVal = 1;
	int iVal = 123456;
	float fVal = 1.23f;
	double dVal = 3.14156;

	printf("%c\n", cVal);
	printf("%i\n", siVal);
	printf("%i\n", iVal);
    printf("%.2f\n", fVal);
	printf("%f\n", dVal);

	const int ciVal = 5;

	printf("%i\n", ciVal);

	/*
	Was passiert beim Compilieren, wenn Sie bei der Definition der konstanten Variablen dieser keinen Wert zuweisen?
	

	Warning: Local Variable 'ciVal' is uninitialized
	
	*/

	/*
	Ist es möglich danach den Wert zu ändern? 


	Nein, da ciVal als const deklariert ist, kann sein Wert nach der Initialisierung nicht mehr geändert werden. Ein Versuch, den Wert zu ändern, würde zu einem Kompilierungsfehler führen.

	*/

}