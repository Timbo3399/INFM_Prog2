#include <stdio.h>

extern double CalcSqrt(double wert);

void CalcPrintSqrt(double dVal)
{
	double dRes = CalcSqrt(dVal);
	printf("Die Wurzel aus %.2f ist %.2f\n", dVal, dRes);
}