#include <stdio.h>

void main() 
{
	int iY = 42;
	int iX = 73;

	/*1.1 Implementieren Sie ein Programm, welches alle arithmetischen Operatoren unter Verwendung der Variablen*/

	/*Grundlegende Arithmetische Operatoren*/
	printf("Addition: %i + %i = %i\n", iY, iX, iY + iX);
	printf("Subtraktion: %i - %i = %i\n", iY, iX, iY - iX);
	printf("Multiplikation: %i * %i = %i\n", iY, iX, iY * iX);
	printf("Division: %i / %i = %i\n", iY, iX, iY / iX);
	printf("Modulus: %i %% %i = %i\n", iY, iX, iY % iX);
	/*Inkrement- und Dekrement-Operatoren*/
	printf("Inkrement: %i++ = %i\n", iY, iY++);
	printf("Dekrement: %i-- = %i\n", iX, iX--);
	/*Unäre Operatoren*/
	printf("Negation: -%i = %i\n", iY, -iY);
	printf("Inversion: ~%i = %i\n", iX, ~iX);

	/*1.2 Implementieren Sie mit iX und einer literalen Konstanten alle relationalen Operatoren.*/

	const int iConst = 50;

	printf("Gleichheit: %i == %i = %i\n", iX, iConst, iX == iConst);
	printf("Ungleichheit: %i != %i = %i\n", iX, iConst, iX != iConst);
	printf("Groesser als: %i > %i = %i\n", iX, iConst, iX > iConst);
	printf("Kleiner als: %i < %i = %i\n", iX, iConst, iX < iConst);
	printf("Goesser oder gleich: %i >= %i = %i\n", iX, iConst, iX >= iConst);
	printf("Kleiner oder gleich: %i <= %i = %i\n", iX, iConst, iX <= iConst);

	/*
	Sind die angezeigten Ergebnisse korrekt?
	Ja
	*/

	/*1.3 Implementieren Sie unter Nutzung von relationalen Operatoren die drei logischen Operatoren*/

	printf("Logisches UND: (%i > %i) && (%i < %i) = %i\n", iX, iConst, iY, iConst, (iX > iConst) && (iY < iConst));
	printf("Logisches ODER: (%i > %i) || (%i < %i) = %i\n", iX, iConst, iY, iConst, (iX > iConst) || (iY < iConst));
	printf("Logisches NICHT: !(%i > %i) = %i\n", iX, iConst, !(iX > iConst));

	/*
	Sind die angezeigten Ergebnisse korrekt?
	Ja
	*/

	/*1.4*/

	unsigned char ucVal1 = 0x5A; //Bitmuster: 01011010
	unsigned char ucVal2 = 0xA5; //Bitmuster: 10100101

	/*bitorientierten Operatoren*/
	printf("Bitweise UND: %02X & %02X = %02X\n", ucVal1, ucVal2, ucVal1 & ucVal2); //Setzt das Ergebnisbit auf 1, wenn beide Operanden an der entsprechenden Stelle 1 sind, sonst 0.
	printf("Bitweise ODER: %02X | %02X = %02X\n", ucVal1, ucVal2, ucVal1 | ucVal2); //Setzt das Ergebnisbit auf 1, wenn mindestens einer der Operanden an der entsprechenden Stelle 1 ist, sonst 0.
	printf("Bitweise XOR: %02X ^ %02X = %02X\n", ucVal1, ucVal2, ucVal1 ^ ucVal2); //Setzt das Ergebnisbit auf 1, wenn genau einer der Operanden an der entsprechenden Stelle 1 ist, sonst 0.
	printf("Bitweise NOT: ~%02X = %02X\n", ucVal1, ~ucVal1); //Setzt das Ergebnisbit auf 1, wenn der Operand an der entsprechenden Stelle 0 ist, sonst 0.
	printf("Bitweise Linksverschiebung: %02X << 2 = %02X\n", ucVal1, ucVal1 << 2); //Schiebt die Bits des Operanden um die angegebene Anzahl von Positionen nach links. Die leeren Stellen werden mit Nullen aufgefüllt.
	printf("Bitweise Rechtsverschiebung: %02X >> 2 = %02X\n", ucVal1, ucVal1 >> 2); //Schiebt die Bits des Operanden um die angegebene Anzahl von Positionen nach rechts. Die leeren Stellen werden mit Nullen aufgefüllt (bei unsigned) oder mit dem Vorzeichenbit (bei signed).

	ucVal1 = ucVal1 ^ ucVal2 ^ ucVal2; //Die XOR-Operation mit demselben Wert (ucVal2) zweimal hintereinander hebt die Wirkung der XOR-Operation auf, da jedes Bit, das durch die erste XOR-Operation geändert wurde, durch die zweite XOR-Operation wieder zurückgesetzt wird. Daher bleibt ucVal1 unverändert.
	printf("%02X", ucVal1);
	/*ucVal1 = ucVal1 ^ ucVal2 ^ ucVal2; ergibt ucVal1, da die XOR-Operation zweimal hintereinander die Wirkung der XOR-Operation aufhebt*/

	/*Wie müssten nach dem C-Coding Styleguide die Klammern für obigen Ausdruck gesetzt werden?
	
	ucVal1 = (ucVal1 ^ ucVal2) ^ ucVal2; oder ucVal1 = ucVal1 ^ (ucVal2 ^ ucVal2); beide Varianten sind korrekt, da die XOR-Operation assoziativ ist, d.h. die Reihenfolge der Operationen keinen Einfluss auf das Ergebnis hat.
	*/
}