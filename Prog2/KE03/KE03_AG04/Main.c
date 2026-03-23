#include <stdio.h>
#include <math.h>

main(void)
{
	double dValA;
	double dValB;
	double dValC;
	double dValD;

	printf("Enter ValA: ");
	scanf_s("%lf", &dValA);

	printf("Enter ValB: ");
	scanf_s("%lf", &dValB);

	printf("Enter ValC: ");
	scanf_s("%lf", &dValC);

	dValD = dValA * sqrt(dValB - dValC);

	printf("ValD: %lf\n", dValD);

	/*
	 * Erkennen Sie unter welcher Bedingung die Berechnung der Wurzel nicht funktioniert?
	 * 
	 * Wenn dValB - dValC < 0
	 * 
	 * Was könnte dies bedeuten? 
	 * 
	 * nan steht für not a number. Da eine negative Wurze zu den komplexen Zahlen gehört, kann sie nicht als reelle Zahl in dem kontext nicht darstllen.
	 */
}